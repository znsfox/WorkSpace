<%--
  Created by IntelliJ IDEA.
  User: fox
  Date: 2020/10/13
  Time: 11:13
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Params</title>
    <script src="WEB-INF/lib/jquery-3.5.1.js"></script>
<%--    javaScript --%>
</head>
<body>
<form id="form" action="./params/commonParams.do">
    <table>
        <tr>
            <td>roleName</td>
            <td><input id="roleName" name="roleName" value=""></td>
        </tr>
        <tr>
            <td>memorandum</td>
            <td><input id="note" name="note"/></td>
        </tr>
        <tr>
            <td align="right"><input type="submit" value="submit"></td>
        </tr>
    </table>
</form>
</body>
</html>
