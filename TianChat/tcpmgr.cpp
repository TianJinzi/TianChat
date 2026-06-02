#include "tcpmgr.h"
#include <QAbstractSocket>
#include <QJsonDocument>
#include "usermgr.h"


TcpMgr::~TcpMgr()
{

}

TcpMgr::TcpMgr():_host(""),_port(0),_b_recv_pending(false),_message_id(0),_message_len(0)
{
    QObject::connect(&_socket,&QTcpSocket::connected,[&](){
        qDebug()<<"Connected to server!";
        //建立连接后发送消息
        emit sig_con_success(true);
    });

    QObject::connect(&_socket,&QTcpSocket::readyRead,[&](){
        //当前有数据可读加到缓冲区去
        _buffer.append(_socket.readAll());
        QDataStream stream(&_buffer,QIODevice::ReadOnly);
        //根据情况选择版本
        stream.setVersion(QDataStream::Qt_6_0);

        forever{
            if(!_b_recv_pending){
                //检查缓冲区中的数据是否足够解析出一个消息头
                if(_buffer.size()<static_cast<int>(sizeof(quint16)*2)){
                    return;//数据不足
                }
                stream>>_message_id>>_message_len;
                _buffer=_buffer.mid(sizeof(quint16)*2);
                qDebug()<<"Message ID:"<<_message_id<<", Length:"<<_message_len;
            }
            //buffer剩余长度检查
            if(_buffer.size()<_message_len){
                _b_recv_pending=true;
                return;
            }
            _b_recv_pending=false;
            //读取消息
            QByteArray messageBody=_buffer.mid(0,_message_len);
            qDebug()<<"receive body msg is"<<messageBody;

            _buffer=_buffer.mid(_message_len);
            handleMsg(ReqId(_message_id),_message_len,messageBody);
        }
    });

    QObject::connect(&_socket,QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::errorOccurred),this
                     ,[this](QAbstractSocket::SocketError socketError){
        qDebug()<<"Error:"<<_socket.errorString();
        switch (socketError) {
        case QAbstractSocket::ConnectionRefusedError:
            qDebug() << "Connection refused by peer or server not running.";
            emit sig_con_success(false);
            break;
        case QAbstractSocket::RemoteHostClosedError:
            qDebug() << "Remote host closed the connection.";
            break;
        case QAbstractSocket::HostNotFoundError:
            qDebug() << "Host not found. Check hostname or IP.";
            emit sig_con_success(false);
            break;
        case QAbstractSocket::SocketTimeoutError:
            qDebug()<<"Connection Timeout!";
            emit sig_con_success(false);
            break;
        case QAbstractSocket::NetworkError:
            qDebug() << "Network error: cable disconnected or WiFi down.";
            // 可以在这里触发重连逻辑
            break;
        default:
            qDebug() << "Other socket error:" << socketError;
            break;
        }
    });

    QObject::connect(&_socket,&QTcpSocket::disconnected,[&](){
        qDebug()<<"Disconnected from server.";
    });
    QObject::connect(this,&TcpMgr::sig_send_data,this,&TcpMgr::slot_send_data);
    //注册消息
    initHandlers();

}

void TcpMgr::initHandlers()
{
    //登录
    _handlers.insert(ID_CHAT_LOGIN_RSP,[this](ReqId id,int len,QByteArray data){
        Q_UNUSED(len);
        qDebug()<<"handle id is "<<id<<" data is "<<data;
        //将QByteArray转换为QJsonDocument
        QJsonDocument jsonDoc=QJsonDocument::fromJson(data);
        //检查转换是否成功
        if(jsonDoc.isNull()){
            qDebug()<<"Failed to create QJsonDocument";
            return;
        }
        QJsonObject jsonObj=jsonDoc.object();
        if(!jsonObj.contains("error")){
            int err=ErrorCodes::ERR_JSON;
            qDebug()<<"Login Failed, err is Json Parse Err"<<err;
            emit sig_login_failed(err);
            return;
        }
        int err=jsonObj["error"].toInt();
        if(err!=ErrorCodes::SUCCESS){
            qDebug()<<"Login Failed ,err is"<<err;
            emit sig_login_failed(err);
            return;
        }

        UserMgr::GetInstance()->SetUid(jsonObj["uid"].toInt());
        UserMgr::GetInstance()->SetName(jsonObj["name"].toString());
        UserMgr::GetInstance()->SetToken(jsonObj["token"].toString());
        emit sig_switch_chatdlg();
    });
}

void TcpMgr::handleMsg(ReqId id,int len,QByteArray data){
    auto find_iter=_handlers.find(id);
    if(find_iter==_handlers.end()){
        qDebug()<<"not found id ["<<id<<" ] to handle;";
        return;
    }
    find_iter.value()(id,len,data);

}

void TcpMgr::slot_tcp_connect(ServerInfo si)
{
    qDebug()<<"receive tcp connect  signal";
    //连接服务器
    qDebug()<<"Connecting to server....";
    _host=si.Host;
    _port=static_cast<uint16_t>(si.Port.toUInt());
    _socket.connectToHost(_host,_port);
}

void TcpMgr::slot_send_data(ReqId reqId,QString data){
    uint16_t id=reqId;

    QByteArray dataBytes=data.toUtf8();
    quint16 len=static_cast<quint16>(dataBytes.size());
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    //设置数据流使用网络字节序
    out.setByteOrder(QDataStream::BigEndian);

    out<<id<<len;
    block.append(dataBytes);
    _socket.write(block);
}


