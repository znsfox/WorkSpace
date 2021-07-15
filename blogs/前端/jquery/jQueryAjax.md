## jQuery Ajax:

AJAX = Asynchronous JavaScript and XML

是与服务器交换数据的技术，它在不重载网页的情况下，实现了对部分网页的更新。



jQuery-load() 方法

jQuery [load() 方法](https://www.w3cschool.cn/jquery/event-load.html)是简单但强大的 AJAX 方法。

load() 方法从服务器加载数据，并把返回的数据放入被选元素中。

**语法:**

```js
$(*selector*).load(*URL,data,callback*); 
```

必需的 *URL* 参数规定您希望加载的 URL。

可选的 *data* 参数规定与请求一同发送的查询字符串键/值对集合。

可选的 *callback* 参数是 load() 方法完成后所执行的函数名称。

回调函数可以设置不同的参数

- *responseTxt* - 包含调用成功时的结果内容
- *statusTXT* - 包含调用的状态
- *xhr* - 包含 [XMLHttpRequest 对象](https://www.w3cschool.cn/xml/xml-http.html)

```js
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="//libs.baidu.com/jquery/1.10.2/jquery.min.js">
</script>
<script>
$(document).ready(function(){
  $("button").click(function(){
    $("#div1").load("/statics/demosource/demo_test.txt",function(responseTxt,statusTxt,xhr){
      if(statusTxt=="success")
        alert("外部内容加载成功!");
      if(statusTxt=="error")
        alert("Error: "+xhr.status+": "+xhr.statusText);
    });
  });
});
</script>
</head>
<body>

<div id="div1"><h2>使用 jQuery AJAX 修改该文本</h2></div>
<button>获取外部内容</button>

</body>
</html>
```





<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<script src="//libs.baidu.com/jquery/1.10.2/jquery.min.js">
</script>
<script>
$(document).ready(function(){
  $("button").click(function(){
    $("#div1").load("/statics/demosource/demo_test.txt",function(responseTxt,statusTxt,xhr){
      if(statusTxt=="success")
        alert("外部内容加载成功!");
      if(statusTxt=="error")
        alert("Error: "+xhr.status+": "+xhr.statusText);
    });
  });
});
</script>
</head>
<body>
## jQuery - AJAX get() 和 post() 方法

jQuery get()和post()方法用于通过HTTP GET和POST请求从服务器请求数据。

