<%--
  Created by IntelliJ IDEA.
  User: fox
  Date: 2020/10/30
  Time: 15:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body
        <%
    //设置请求属性
    request.setAttribute("id", 11L);
    //转发给控制器
    request.getRequestDispatcher("./attribute/requestAttribute.do").forward(request, response);
        %>>
</body>
</html>
