const emailModule = require('./email');

async function test() {
    console.log("开始测试邮件发送...");
    try {
        const result = await emailModule.SendMail({
            from: '18835695290@163.com',
            to: '2716514148@qq.com',
            subject: '测试邮件',
            text: '这是一封测试邮件'
        });
        console.log("✅ 测试成功！", result);
    } catch (err) {
        console.error("❌ 测试失败！", err.message);
    }
}

test();