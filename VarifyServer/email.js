const nodemailer = require('nodemailer');
const config_module = require("./config")

/**
 * 创建发送邮件的代理
 */
let transport = nodemailer.createTransport({
    host: 'smtp.163.com',
    port: 465,
    secure: true,
    auth: {
        user: config_module.email_user, // 发送方邮箱地址
        pass: config_module.email_pass // 邮箱授权码或者密码
    }
});

/**
 * 发送邮件的函数
 * @param {*} mailOptions_ 发送邮件的参数
 * @returns 
 */
// function SendMail(mailOptions_){
//     return new Promise(function(resolve, reject){
//         transport.sendMail(mailOptions_, function(error, info){
//             if (error) {
//                 console.log(error);
//                 reject(error);
//             } else {
//                 console.log('邮件已成功发送：' + info.response);
//                 resolve(info.response);
//             }
//         });
//     })
// }

function SendMail(mailOptions_){
    return new Promise(function(resolve, reject){
        //关键：10秒超时强制结束，防止无限等待
        const timeoutId = setTimeout(() => {
            console.error("邮件发送超时(10秒),强制终止");
            reject(new Error("邮件发送超时:连接SMTP服务器超时"));
        }, 10000);

        transport.sendMail(mailOptions_, function(error, info){
            // 清除超时计时器
            clearTimeout(timeoutId);
            
            if (error) {
                console.error("邮件发送失败，详细错误：", error);
                reject(error);
            } else {
                console.log('邮件已成功发送：' + info.response);
                resolve(info.response);
            }
        });
    })
}

module.exports.SendMail = SendMail