Axios是一个基于promise的HTTP库，可以用在浏览器或者node.js中。



### 手册说明：

axios不是一种新的技术，是一个基于promise，用于浏览器和noe.js的HTTP客户端，本质上也是对原生XHR（XMLHttpRequest ）的封装，只不过它是promise的实现版本，符合最新的ES规范，有以下特点：

- 从浏览器创建XHR
- 从node.js创建http请求
- 支持Promise API
- 拦截请求和响应
- 转换请求数据和响应数据
- 取消请求
- 自动转换JSON数据
- 支持防御CSRF



CSRF：（Cross-site request forgery跨站**请求**伪造，也被称为“One Click Attack”或者Session Riding，通常缩写为CSRF或者XSRF，是一种对网站的恶意利用。CSRF定义的主语是”请求“，是一种跨站的伪造的请求，指的是跨站伪造用户的请求，模拟用户的操作.





### 优点：

### 1.支持node端和浏览器端

同样的API，node和浏览器全支持，平台切换无压力

### 2.支持 Promise

使用Promise管理异步，告别传统callback方式

### 3.丰富的配置项

支持拦截器等高级配置

### 4.社区支持

axios相关的npm包数量一直在增长







