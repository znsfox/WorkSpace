搭建独立的分布式文件管理系统，FastDFS + Nginx组合无疑是最佳解决方案。

FastDFS 类似 google FS，属于应用级文件系统**，不是通用的文件系统，只能通过专有 API 访问**，目前提供了 C 和 Java SDK ，以及 PHP 扩展 SDK。

FastDFS 解决大容量文件存储问题，追求高性能和高扩展性，可以看作是基于key/value存储系统，key为文件ID,value为文件内容，因此称作做工文件存储系统更为合适。

常见的图片存储、视频存储、文档存储等等我们都可以采用 FastDFS 来做。