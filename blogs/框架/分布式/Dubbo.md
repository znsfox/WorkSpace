Apache Dubbo是一款高性能轻量级的开源Java RPC框架，有三大核心能力：

- 面向接口的远程方法调用
- 智能容错和负载均衡
- 服务自动注册和发现

其致力于提供高性能和透明化的RPC（remote procedure call)远程调用方案以及SOA（Service-oriented architecture)服务治理方案。



### RPC：

通过网络从远程计算机程序上请求服务，而不需要了解底层网络技术的协议。

![RPC原理图](https://camo.githubusercontent.com/8c3612d79c66a672cace6d1d91df7c1f7419ef4f5cde1fd52be8ddee166d5029/687474703a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f31382d31322d362f33373334353835312e6a7067)

1. 服务消费方（client）调用以本地调用方式调用服务；
2. client stub接收到调用后负责将方法、参数等组装成能够进行网络传输的消息体；
3. client stub找到服务地址，并将消息发送到服务端；
4. server stub收到消息后进行解码；
5. server stub根据解码结果调用本地的服务；
6. 本地服务执行并将结果返回给server stub；
7. server stub将返回结果打包成消息并发送至消费方；
8. client stub接收到消息，并进行解码；
9. 服务消费方得到最终结果。

### CAP:

- consistency:

数据一致性，所有节点拥有数据的最新版本

- availability:

可用性，数据具备高可用性

- partition-tolerance:

容忍网络出现分区，分区之间网络不可达



一般我们说的分布式系统，**P：分区容错性(partition-tolerance)这个是必需的**，这是客观存在的。

**CAP是无法完全兼顾的**，从上面的例子也可以看出，我们可以选AP，也可以选CP。但是，要**注意的是**：不是说选了AP，C就完全抛弃了。不是说选了CP，A就完全抛弃了！



**在CAP理论中，C所表示的一致性是强一致性**（每个节点的数据都是最新版本）

弱一致性：相对于强一致性而言，它不保证能得到最新的值 

最终一致性：放宽对时间的要求，在被调完成操作响应的某个时间点，被调多个节点的数据最终达成一致。



所以，**CAP理论定义的其实是在容忍网络分区的条件下，“强一致性”和“极致可用性”无法同时达到**。

### SOA:

把工程按照业务逻辑拆分成服务层、表现层两个工程。服务层包含业务逻辑，只需要对外提供服务即可。

表现层只需要处理和页面的交互，业务逻辑都是调用服务层的业务逻辑来实现。

两个重要角色：服务提供者(provider)	服务使用者(Consumer)

![为什么要用 Dubbo](https://camo.githubusercontent.com/e0d1d251e8138b1b2ed228e47845e6da1fd66d61615c7f492716d39dfbc75067/687474703a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f31382d392d32362f34333035303138332e6a7067)



### 分布式：

分布式就是我们把整个系统拆成不同的服务，然后把这些服务放在不同的服务器上，以此来减轻单体服务的压力提高并发量和性能。

比如电商系统可以简单地拆分成订单系统、商品系统、登陆系统等等。



### Dubbo:

四个特性：

1. **负载均衡**——同一个服务部署在不同的机器时该调用那一台机器上的服务。
2. **服务调用链路生成**——随着系统的发展，服务越来越多，服务间依赖关系变得错踪复杂，甚至分不清哪个应用要在哪个应用之前启动，架构师都不能完整的描述应用的架构关系。Dubbo 可以为我们解决服务之间互相是如何调用的。
3. **服务访问压力以及时长统计、资源调度和治理**——基于访问压力实时管理集群容量，提高集群利用率。
4. **服务降级**——某个服务挂掉之后调用备用服务。



#### 架构：

![Dubbo 架构](https://camo.githubusercontent.com/f35a9a40dc7918617bb12bf77c355b75758a940c4d70cc490be142780151e2d6/687474703a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f31382d392d32362f34363831363434362e6a7067)

- **Provider：** 暴露服务的服务提供方
- **Consumer：** 调用远程服务的服务消费方
- **Registry：** 服务注册与发现的注册中心
- **Monitor：** 统计服务的调用次数和调用时间的监控中心
- **Container：** 服务运行容器

**调用关系说明：**

1. 服务容器负责启动，加载，运行服务提供者。
2. 服务提供者在启动时，向注册中心注册自己提供的服务。
3. 服务消费者在启动时，向注册中心订阅自己所需的服务。
4. 注册中心返回服务提供者地址列表给消费者，如果有变更，注册中心将基于长连接推送变更数据给消费者。
5. 服务消费者，从提供者地址列表中，基于软负载均衡算法，选一台提供者进行调用，如果调用失败，再选另一台调用。
6. 服务消费者和提供者，在内存中累计调用次数和调用时间，定时每分钟发送一次统计数据到监控中心。

**重要知识点总结：**

- **注册中心负责服务地址的注册与查找，相当于目录服务，服务提供者和消费者只在启动时与注册中心交互，注册中心不转发请求，压力较小**
- **监控中心负责统计各服务调用次数，调用时间等，统计先在内存汇总后每分钟一次发送到监控中心服务器，并以报表展示**
- **注册中心，服务提供者，服务消费者三者之间均为长连接，监控中心除外**
- **注册中心通过长连接感知服务提供者的存在，服务提供者宕机，注册中心将立即推送事件通知消费者**
- **注册中心和监控中心全部宕机，不影响已运行的提供者和消费者，消费者在本地缓存了提供者列表**
- **注册中心和监控中心都是可选的，服务消费者可以直连服务提供者**
- **服务提供者无状态，任意一台宕掉后，不影响使用**
- **服务提供者全部宕掉后，服务消费者应用将无法使用，并无限次重连等待服务提供者恢复**

#### Dubbo 工作原理

[![Dubbo 工作原理](https://camo.githubusercontent.com/e85b6b7976506cf3d8ee439b94b6ead5515c2bac931aaaaa7139878f9248024f/687474703a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f31382d392d32362f36343730323932332e6a7067)](https://camo.githubusercontent.com/e85b6b7976506cf3d8ee439b94b6ead5515c2bac931aaaaa7139878f9248024f/687474703a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f31382d392d32362f36343730323932332e6a7067)

图中从下至上分为十层，各层均为单向依赖，右边的黑色箭头代表层之间的依赖关系，每一层都可以剥离上层被复用，其中，Service 和 Config 层为 API，其它各层均为 SPI。

**各层说明**：

- 第一层：**service层**，接口层，给服务提供者和消费者来实现的
- 第二层：**config层**，配置层，主要是对dubbo进行各种配置的
- 第三层：**proxy层**，服务接口透明代理，生成服务的客户端 Stub 和服务器端 Skeleton
- 第四层：**registry层**，服务注册层，负责服务的注册与发现
- 第五层：**cluster层**，集群层，封装多个服务提供者的路由以及负载均衡，将多个实例组合成一个服务
- 第六层：**monitor层**，监控层，对rpc接口的调用次数和调用时间进行监控
- 第七层：**protocol层**，远程调用层，封装rpc调用
- 第八层：**exchange层**，信息交换层，封装请求响应模式，同步转异步
- 第九层：**transport层**，网络传输层，抽象mina和netty为统一接口
- 第十层：**serialize层**，数据序列化层，网络传输需要

#### 再来看看 Dubbo 提供的负载均衡策略

在集群负载均衡时，Dubbo 提供了多种均衡策略，默认为 `random` 随机调用。可以自行扩展负载均衡策略，参见：[负载均衡扩展](https://dubbo.gitbooks.io/dubbo-dev-book/content/impls/load-balance.html)。

备注:下面的图片来自于：尚硅谷2018Dubbo 视频。

####  Random LoadBalance(默认，基于权重的随机负载均衡机制)

- **随机，按权重设置随机概率。**
- 在一个截面上碰撞的概率高，但调用量越大分布越均匀，而且按概率使用权重后也比较均匀，有利于动态调整提供者权重。

[![基于权重的随机负载均衡机制](https://camo.githubusercontent.com/2c9244523351783385bb1abd24f7a91782c8202f13c4be259651e3b9f30d5bab/687474703a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f31382d31322d372f37373732323332372e6a7067)](https://camo.githubusercontent.com/2c9244523351783385bb1abd24f7a91782c8202f13c4be259651e3b9f30d5bab/687474703a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f31382d31322d372f37373732323332372e6a7067)

#### RoundRobin LoadBalance(不推荐，基于权重的轮询负载均衡机制)

- 轮循，按公约后的权重设置轮循比率。
- 存在慢的提供者累积请求的问题，比如：第二台机器很慢，但没挂，当请求调到第二台时就卡在那，久而久之，所有请求都卡在调到第二台上。

[![基于权重的轮询负载均衡机制](https://camo.githubusercontent.com/63f0c18eb7fe6740af8b3057be8bed6bc2ffb5564008dafb506e5f6045166918/687474703a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f31382d31322d372f39373933333234372e6a7067)](https://camo.githubusercontent.com/63f0c18eb7fe6740af8b3057be8bed6bc2ffb5564008dafb506e5f6045166918/687474703a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f31382d31322d372f39373933333234372e6a7067)

#### LeastActive LoadBalance

- 最少活跃调用数，相同活跃数的随机，活跃数指调用前后计数差。
- 使慢的提供者收到更少请求，因为越慢的提供者的调用前后计数差会越大。

#### ConsistentHash LoadBalance

- **一致性 Hash，相同参数的请求总是发到同一提供者。(如果你需要的不是随机负载均衡，是要一类请求都到一个节点，那就走这个一致性hash策略。)**
- 当某一台提供者挂时，原本发往该提供者的请求，基于虚拟节点，平摊到其它提供者，不会引起剧烈变动。
- 算法参见：http://en.wikipedia.org/wiki/Consistent_hashing
- 缺省只对第一个参数 Hash，如果要修改，请配置 `<dubbo:parameter key="hash.arguments" value="0,1" />`
- 缺省用 160 份虚拟节点，如果要修改，请配置 `<dubbo:parameter key="hash.nodes" value="320" />`

#### 配置方式

**xml 配置方式**

服务端服务级别

```
<dubbo:service interface="..." loadbalance="roundrobin" />
```

客户端服务级别

```
<dubbo:reference interface="..." loadbalance="roundrobin" />
```

服务端方法级别

```
<dubbo:service interface="...">
    <dubbo:method name="..." loadbalance="roundrobin"/>
</dubbo:service>
```

客户端方法级别

```
<dubbo:reference interface="...">
    <dubbo:method name="..." loadbalance="roundrobin"/>
</dubbo:reference>
```

**注解配置方式：**

消费方基于基于注解的服务级别配置方式：

```
@Reference(loadbalance = "roundrobin")
HelloService helloService;
```

### zookeeper宕机与dubbo直连的情况

zookeeper宕机与dubbo直连的情况在面试中可能会被经常问到，所以要引起重视。

在实际生产中，假如zookeeper注册中心宕掉，一段时间内服务消费方还是能够调用提供方的服务的，实际上它使用的本地缓存进行通讯，这只是dubbo健壮性的一种体现。

**dubbo的健壮性表现：**

1. 监控中心宕掉不影响使用，只是丢失部分采样数据
2. 数据库宕掉后，注册中心仍能通过缓存提供服务列表查询，但不能注册新服务
3. 注册中心对等集群，任意一台宕掉后，将自动切换到另一台
4. 注册中心全部宕掉后，服务提供者和服务消费者仍能通过本地缓存通讯
5. 服务提供者无状态，任意一台宕掉后，不影响使用
6. 服务提供者全部宕掉后，服务消费者应用将无法使用，并无限次重连等待服务提供者恢复

我们前面提到过：注册中心负责服务地址的注册与查找，相当于目录服务，服务提供者和消费者只在启动时与注册中心交互，注册中心不转发请求，压力较小。所以，我们可以完全可以绕过注册中心——采用 **dubbo 直连** ，即在服务消费方配置服务提供方的位置信息。

**xml配置方式：**

```
<dubbo:reference id="userService" interface="com.zang.gmall.service.UserService" url="dubbo://localhost:20880" />
```

**注解方式：**

```
 @Reference(url = "127.0.0.1:20880")   
 HelloService helloService;
```







### 使用：



配置加载流程：

1、Dubbo支持多层级的配置，并按预定优先级自动实现配置间的覆盖，最终所有配置汇聚到数据总线URL后，驱动后续的服务暴露、引用等流程。

2、ApplicationConfig、ServiceConfig、ReferenceConfig可以被理解成配置来源的一种，是直接面向用户编程的配置采集方式。

3、配置格式以properties为主，在配置内容上遵循缩写的path-based的命名规范。

#### 配置

目前Dubbo支持的所有配置都是`.properties`格式的，包括`-D`、`Externalized Configuration`等，`.properties`中的所有配置项遵循一种`path-based`的配置格式：

```fallback
# 应用级别
dubbo.{config-type}[.{config-id}].{config-item}={config-item-value}
# 服务级别
dubbo.service.{interface-name}[.{method-name}].{config-item}={config-item-value}
dubbo.reference.{interface-name}[.{method-name}].{config-item}={config-item-value}
# 多配置项
dubbo.{config-type}s.{config-id}.{config-item}={config-item-value}
```

应用级别

```fallback
dubbo.application.name=demo-provider
dubbo.registry.address=zookeeper://127.0.0.1:2181
dubbo.protocol.port=-1
```

服务级别

```fallback
dubbo.service.org.apache.dubbo.samples.api.DemoService.timeout=5000
dubbo.reference.org.apache.dubbo.samples.api.DemoService.timeout=6000
dubbo.reference.org.apache.dubbo.samples.api.DemoService.sayHello.timeout=7000
```

多配置项

```fallback
dubbo.registries.unit1.address=zookeeper://127.0.0.1:2181
dubbo.registries.unit2.address=zookeeper://127.0.0.1:2182

dubbo.protocols.dubbo.name=dubbo
dubbo.protocols.dubbo.port=20880
dubbo.protocols.hessian.name=hessian
dubbo.protocols.hessian.port=8089
```

扩展配置

```fallback
dubbo.application.parameters.item1=value1
dubbo.application.parameters.item2=value2
dubbo.registry.parameters.item3=value3
dubbo.reference.org.apache.dubbo.samples.api.DemoService.parameters.item4=value4
```

#### 启动时检查

Dubbo缺省会在启动时检查依赖的服务是否可用，不可用时会抛出异常，阻止spring初始化完成。

**默认：check="true"**

如果spring窗口是懒加载的，或者量通过API编程延迟引用服务，会关闭check，否则服务临时不可用，会抛出异常