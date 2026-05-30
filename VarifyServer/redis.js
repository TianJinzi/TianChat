// 1. 导入模块
const config_module = require('./config')
const Redis = require("ioredis");

// 2. 创建 Redis 客户端实例
const RedisCli = new Redis({
    host: config_module.redis_host,       // Redis 服务器主机名
    port: config_module.redis_port,       // Redis 服务器端口号
    password: config_module.redis_passwd, // Redis 密码
    //////
    retryStrategy(times) {
        return Math.min(times * 50, 2000);
    }
});

// 3. 监听 Redis 连接错误
RedisCli.on("error", function (err) {
    console.log("RedisCli connect error");
    // RedisCli.quit(); // 出错时关闭客户端
});

// 4. 封装 GET 命令：根据 key 获取 value
async function GetRedis(key) {
    try {
        const result = await RedisCli.get(key)
        if (result == null) {
            console.log('result:', '<' + result + '>', 'This key cannot be find...')
            return null
        }
        console.log('Result:', '<' + result + '>', 'Get key success!...');
        return result
    } catch (error) {
        console.log('getRedis error is', error);
        return null
    }
}

/**
 * 根据key查询redis中是否存在key
 * @param {*} key Redis键名
 * @returns {Promise<number|null>} 存在返回1，不存在返回null，出错返回null
 */
async function QueryRedis(key) {
    try {
        // 执行 Redis EXISTS 命令，查询key是否存在
        const result = await RedisCli.exists(key);
        // 判断结果：返回0表示key不存在
        if (result === 0) {
            console.log('result:<','<'+result+'>','This key is null...');
            return null;
        }
        // key存在，返回结果（值为1）
        console.log('Result:','<'+result+'>','With this value!...');
        return result;
    } catch(error) {
        // 捕获所有错误（连接错误、Redis服务错误等）
        console.log('QueryRedis error is', error);
        return null;
    }
}


/**
 * 设置key和value，并设置过期时间
 * @param {*} key Redis键
 * @param {*} value Redis值
 * @param {*} exptime 过期时间（单位：秒）
 * @returns {Promise<boolean>} 操作是否成功
 */
async function SetRedisExpire(key, value, exptime) {
    try {
        // 1. 执行 Redis SET 命令，设置键值对
        await RedisCli.set(key, value);
        // 2. 执行 Redis EXPIRE 命令，设置键的过期时间
        await RedisCli.expire(key, exptime);
        return true;
    } catch (error) {
        console.log('SetRedisExpire error is', error);
        return false;
    }
}

/*
*退出函数
*/

function Quit(){
    RedisCli.quit();
}

module.exports={GetRedis,QueryRedis,Quit,SetRedisExpire}