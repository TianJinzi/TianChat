let code_prefix = "code_";

const Errors = {
  Success: 0,
  RedisErr: 1,
  Exception: 2,
  /*
  *下面是自己增加
  */
  SendMailError: 3,
};

module.exports={code_prefix,Errors}