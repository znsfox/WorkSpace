## Servlet 简介			

### servlet是什么？

Java Servlet是运行在Web服务器或应用服务器上的程序，它是作为来自Web浏览器或其他HTTP客户端的请求和HTTP服务器上的数据库或应用程序之间中间层。

使用Servlet，可以收集来自网页表单的用户输入，呈现来自数据库或其他源的记录，还可以动态创建网页。

**特点**：

- Servlet在web服务器的地址空间内执行，这样就没有必要再创建一个单独的进程来处理每个客户端请求。
- Servlet是独立于平台的，因为它是用Java编写的。
- java类库的全部功能对Servlet来说都是可用的。



### servlet的架构：

![Servlet 架构](https://atts.w3cschool.cn/attachments/day_160820/201608201310026613.jpg)



### servlet任务：

读取客户端（浏览器）发送的显式数据。这包括网页上的HTML表单。

读取客户端改善的隐式HTTP请求数据，这包括cookies,媒体类型和浏览器能理解的压缩格式等等。

处理数据并生成结果，这个过程可能需要访问数据库，执行RMI（远程方法调用），调用web服务，或直接计算出对应的响应。

发送显式的数据（即文档）到客户端（浏览器），该文档的格式可以是多种多样的，包括gif,xml,html,txt等。

发送隐式的HTTP响应到客户端，这包括告诉浏览器或其他客户端返回的文档类型，设置cookies和缓存参数，以及其他类似的任务。



### servlet包：

Servlet 可以使用 **javax.servlet** 和 **javax.servlet.http** 包创建，它是 Java 企业版的标准组成部分，Java 企业版是支持大型开发项目的 Java 类库的扩展版本。





## servlet生命周期：

servlet通过init()进行初始化。

service()方法来处理客户端的请求。

destroy()方法终止。

最后，Servlet是由JVM的垃圾回收器进行回收的。



### intit()

init()方法被设计成只调用一次，它在第一次创建Servlet时被调用，在后续每次用户讲法时不再调用，因此它是用于一次性初始化。

servlet创建于第一次调用对于该Servlet的URL时，当然也可以指定servlet在服务器第一次被调用时加载。

当用户调用一个servlet时，应付创建一个servlet实例，每一个用户请求都会产生一个新的线程，适当的时候移交给doGet或doPost访求。init()简单地创建或加载一些数据，这些数据用于Servlet的整个生命周期。



### service()

service方法是执行实际任务的重要方法，

Servlet容器（即web服务器）调用service()方法处理来自客户端的请求，并把格式化的响应写回给客户端。

每次服务器收到一个servlet请求时，服务器会产生一个新的线程并调用服务。

service()方法检查HTTP请求的类型（如get,post,delete,put),并在适当的时候调用doGet,doPut,doPost,doDelete等方法。

service由容器调用，所以不用在service()方法做任何动作。只需要根据客户端的请求类型来重载doGet()或doPost()即可。



#### doGet()

GET请求来来自于一个URL的正常请求，或者来自于一个未指定的method的HTML表单。它由doGet处理。



#### doPost()

POST请求来自于一个特别指定了Method为post的HTMl表单。它由doPost()方法处理。



### destroy()

destroy()方法只会被 调用一次，在servlet生命周期结束时被调用。destroy()可以让您的servlet关闭数据库连接，停止后台进程，把cookie列表和计数器写入磁盘，并执行其他类似的清理活动。

在执行destroy()方法后，servlet对象被标记为回收。



### 架构图：

第一个到达服务器的HTTP请求被委派到Servlet容器。

Servlet容器在调用Service()方法之前加载servlet.

然后Servlet容器处理多个线程产生的多个请求，每个线程执行一个单一的Servlet实例的service（）方法。

![Servlet 生命周期](https://atts.w3cschool.cn/attachments/day_160820/201608201303222781.jpg)

