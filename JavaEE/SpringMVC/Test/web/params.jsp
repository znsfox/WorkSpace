<%--
  Created by IntelliJ IDEA.
  User: fox
  Date: 2020/10/29
  Time: 14:42
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
    <script src="https://s3.pstatp.com/cdn/expire-1-M/jquery/3.3.1/jquery.min.js"></script>

</head>
<body>
<!-- 根据你的需要改变请求url -->
<form id="form" action="./params/commonParams.do">
    <table>
        <tr>
            <td>角色名称</td>
            <td><input id="roleName" name="roleName" value="" /></td>
            <!--
            <td><input id="role_name" name="role_name" value="" /></td>
            -->
        </tr>
        <tr>
            <td>备注</td>
            <td><input id="note" name="note" /></td>
        </tr>
        <tr>
            <td></td>
            <td align="right"><input type="submit" value="提交" /></td>
        </tr>
    </table>
</form>
</body>
</html>
