<%--
  Created by IntelliJ IDEA.
  User: fox
  Date: 2020/11/22
  Time: 16:38
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>参数</title>
    <!-- 加载Query文件-->
    <script src="https://s3.pstatp.com/cdn/expire-1-M/jquery/3.3.1/jquery.min.js" ></script>
    <script type="text/javascript">
        $(document).ready(function () {
            //模拟30000个异步请求，进行并发
            var max = 3;
            for (var i = 1; i <= max; i++) {
                //jQuery的post请求，请注意这是异步请求
                $.post({
                    //请求抢id为1的红包
                    //根据自己请求修改对应的url和大红包编号
                    url: "./userRedPacket/grapRedPacket.do?redPacketId=1&userId=" + i,
                    //成功后的方法
                    success: function (result) {
                    }
                });
            }
        });
    </script>
</head>
<body>
</body>
</html>
