Channel  & Buffer



### channel





## BIO:

<img src="https://raw.githubusercontent.com/znsfox/PicGo/master/img/20210407184007.png" alt="image-20210407184007614" style="zoom:67%;" />

同步并阻塞，服务器实现模式为一个连接一个线程，即客户端有连接请求时，服务器端就需要启动一个线程进行处理，如果这个连接不做任何事情会造成不必要的线程开销



## NIO

<img src="../../../../../AppData/Roaming/Typora/typora-user-images/image-20210407183925698.png" alt="image-20210407183925698" style="zoom:67%;" />

服务器实现模式为一个线程处理多个请求，客户端发送的连接请求都会注册到多路复用器，多路复用器轮询到连接有I/O请求就进行处理





面向`缓冲区`的，基于`通道`的IO操作



核心：

- Channel
- Buffer
- Selector



**非阻塞模式：**

使一个线程从某通道发送请求或者读取数据，但是它仅能得到目前可用的数据，如果目前没有数据可用时，就什么都不会获取，而不是保持线程阻塞，所以直到数据变得可读取之前，该线程可以继续去做其他的事情，非阻塞也是如此。



```java
Buffer clear() 清空缓冲区并返回对缓冲区的引用
Buffer flip() 为 将缓冲区的界限设置为当前位置，并将当前位置充值为 0
int capacity() 返回 Buffer 的 capacity 大小
boolean hasRemaining() 判断缓冲区中是否还有元素
int limit() 返回 Buffer 的界限(limit) 的位置
Buffer limit(int n) 将设置缓冲区界限为 n, 并返回一个具有新 limit 的缓冲区对象
Buffer mark() 对缓冲区设置标记
int position() 返回缓冲区的当前位置 position
Buffer position(int n) 将设置缓冲区的当前位置为 n , 并返回修改后的 Buffer 对象
int remaining() 返回 position 和 limit 之间的元素个数
Buffer reset() 将位置 position 转到以前设置的 mark 所在的位置
Buffer rewind() 将位置设为为 0， 取消设置的 mark
```



### 缓冲区的数据操作

```java
Buffer 所有子类提供了两个用于数据操作的方法：get()put() 方法
取获取 Buffer中的数据
get() ：读取单个字节
get(byte[] dst)：批量读取多个字节到 dst 中
get(int index)：读取指定索引位置的字节(不会移动 position)
    
放到 入数据到 Buffer 中 中
put(byte b)：将给定单个字节写入缓冲区的当前位置
put(byte[] src)：将 src 中的字节写入缓冲区的当前位置
put(int index, byte b)：将指定字节写入缓冲区的索引位置(不会移动 position)
```

**使用Buffer读写数据一般遵循以下四个步骤：**

* 1.写入数据到Buffer
* 2.调用flip()方法，转换为读取模式
* 3.从Buffer中读取数据
* 4.调用buffer.clear()方法或者buffer.compact()方法清除缓冲区



### channel

1、通道可以进行读写，而流只能进行读或者只能进行写。

通道可以实现异步读写数据

通道可以缓冲读写数据，也可以写数据到缓冲。

2、BIO中的Stream是单向的，列如 FileInputStream只能进行读取数据的操作，而NIO中的通道Channel是双向的，可以读操作，也可以写操作

3、Channel在NIO中是一个接口





## AIO

异步非阻塞，服务器实现模式为一个有效请求一个线程，客户端的请求都是由OS先完成了再通知服务器应用去启动线程进行处理，`一般适用于连接数较多，且连接时间较长的应用`



区别：

BIO适用于连接数目比较小且固定的架构，这种方式对服务器资源要求比较高，并发局限于应用中



NIO适用于适用于连接数目比较多但是时间短的项目，比如聊天系统，弹幕系统和服务器之间的通讯。



AIO适用于连接数目多且连接时间比较长的架构，比如相册服务器，充分调用OS参与并发操作。





### 伪异步I/O编程

伪异步I/O的通信框架，采用**线程池**和**任务队列**实现，当客户端接入时，将客户端的Socket封闭成一个Task,(该任务实现java.lang.Runnable线程任务的接口)交给后端的线程池进行处理。`JDK的线程池维护一个消息队列和N个活跃的线程`，对消息队列中Socket任务进行处理，由于线程池中可以设置消息队列的大小和最大线程数，因此它的资源占用是可控的。



<img src="../../../../../Downloads/Compressed/%E5%A4%A7%E5%8E%82%E9%9D%A2%E8%AF%95%E4%B9%8BIO%E6%A8%A1%E5%BC%8F%E8%AF%A6%E8%A7%A3%E8%B5%84%E6%96%99/%E8%AE%B2%E4%B9%89/BIO%E3%80%81NIO%E3%80%81AIO.assets/image-20200619085953166.png?lastModify=1617842503" alt="image-20200619085953166" style="zoom:67%;" />







带有 Future和promise的类型和异步方法配合使用。



## Netty



接口：

- Future
- Promise



#### ChannelActive 

会在channel建立成功后触发active事件





协议解析