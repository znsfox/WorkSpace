<%@ page import="fox.pojo.Role" %><%--
  Created by IntelliJ IDEA.
  User: fox
  Date: 2020/10/30
  Time: 16:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    Role role = (Role) session.getAttribute("role");
    out.println();
    out.println("id = " + role.getId() + "<p/>");
    out.println("roleName = " + role.getRoleName() + "<p/>");
    out.println("note = " + role.getNote() + "<p/>");
    Long id = (Long) session.getAttribute("id");
    out.println("id = " + id + "<p/>");
%>
</body>
</html>
