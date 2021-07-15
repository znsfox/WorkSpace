## 基础：

### 什么是JWT?

jwt是一个开放标准，用于在各方之间以json对象安全地传输信息，此信息可以验证和信任，因为它基于数字签名。

类似于令牌，可以完成数字加密和签名。



基于JWT验证：

<img src="https://raw.githubusercontent.com/znsfox/PicGo/master/img/20210331120947.png" alt="image-20210331120946932" style="zoom: 80%;" />





### 认证流程

- 首先，前端通过web表单将自己的用户名和密码发送到后端的接口，这个过程一般是一个HTTP POST请求，建议的方式是通过ssl加密的传输，从而避免敏感信息被嗅探。
- 后端核对用户名和密码后，将用户的id等其他信息作为JWT Payload(负载), 将其与头部分别进行Base64编码拼接后签名，形成一个JWT（Token),形成的JWTY就是一个形同lll.zzz.xxx的字符串。token head.payload.singnature
- 后端将JWT字符串将为登陆成功的返回结果给前端。前端可以将返回的结果保存在localStorage或者是sessionStorage上，退出登陆时，前端删除保存的JWT即可。
- 前端在请求的时候将JWT放在Head的Authorization位，解决（XSS和XSRF的问题）
- 后端检查是否存在，验证JWT的有效性。检查签名是否正确，检查token是否过期，检查toekn的接收方是否是自己。
- 验证通过后，后端使用JWT中包含的其他逻辑操作，返回相应的结果。



### JWT结构：

#### 令牌组成

1.Heander : 令牌的类型和签名的算法，使用Base64编码组成。

2.Payload ： 其中包含声明，声明式有关实体和其他数据的声明，不要放敏感的信息。使用Base64编码。

3.Signature： 前面的一部分是通过Base64进行加密的，前端可以解开知道里面的信息。singnature需要使用经过编码后的header和payload以及我们提供的一个密钥，通过header中指定的方法进行签名，作用是防止jwt被篡改。



拦截之后转换为json

```
String json = new ObjectMapper().writeValueAsString(map);
response.setContentType("application/json;character=UTF-8");
response.getWriter().println(json);
```

