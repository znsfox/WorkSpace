## 核心概念：

RabbitMQ整体上是一个生产者与消费者模型，主要负责接收、存储和转发消息。

消息传递的过程类似于： **当你将一个包裹送到邮局，邮局会暂存并最终将邮件通过邮递员送到收件人的手上，RabbitMQ就好比是邮局、邮箱和邮递员组成的一个系统。**类似于一种交换机模型。

整体模型架构如下：

![图1-RabbitMQ 的整体模型架构](https://camo.githubusercontent.com/6ba7ff34904c9491910064f349eb85007e1a62456a7800223fd1f1caf26d9e43/687474703a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f31382d31322d31362f39363338383534362e6a7067)

### 生产者和消费者：

消息一般分为两部分，消息头和消息体，消息体是不透明的，而**消息头则由一系列的可选属性**构成。

例如：routing-key(路由键)，priority(相对于其他消息的优先权)，delivery-mode(该消息可能需要持久性存储)等

生产者把消息交给RabbitMQ之后，RabbitMQ会根据消息头将消息发送给感兴趣的consumer.

### Exchange(交换器)：

在RabbitMQ中，消息并不是直接被投递到Queue(消息队列)中的，中间必须经过exchange这一层，Exchange会把我们的消息分配到Queue中。

Exchange用来接收生产者发送的消息并将这些消息路由给服务器中的Queue,如果路由不到，或许会返回给Producer,或许会被直接丢弃。

这里可以将RabbitMQ中的交换器看做是一个简单的实体。

RabbitMQ的交换器有四种类型，分别为

direct(默认)：

fanout:

topic:

headers:

不同类型的RabbitMQ转发消息的策略有所区别。

------

生产者将消息发送给交换器的时候，一般会指定一个**RoutingKey**(路由键)，用来指定这个消息的路由规则，而RoutingKey需要与交换器类型和BingKey（绑定键）联合使用才能最终生效。

RabbitMQ通过Binding将Exchange与Queue关联起来，在绑定的时候一般会指定一个BindingKey，这样RabbitMQ就知道如何将消息路由到队列了。

![image-20201220171435925](https://raw.githubusercontent.com/znsfox/PicGo/master/img/20201220171436.png)

一个绑定就是基于路由键将交换器和消息队列连接起来的路由规则，所以可以将交换器理解成一个由绑定构成的路由表。

Exchange和Queue的绑定可以是多对多的关系。

------

### 消息队列：

Queue可以用来保存消息直到发送给Consumer.它是消息的容器，也是消息的终点，一个消息可投入一个或多个队列。

**消息一起在队列里，等待消息连接到这个队列将其取走。**

RabbitMQ有消息只能存储在Queue中，和kafka相反，后者只能存储在topic这个逻辑层面 ，而相对应的队列逻辑只是topic实际存储文件中的位移标识。

多个Consumer可以订阅同一个队列，这里队列中的消息会被平均分摊（即Round-Robin，轮询）给多个Consumer进行处理，可以避免消息被重复消费。

RabbitMQ不支持队列层面的广播消费。

------



### Broker:

对于RabbitMQ来说，一个RabbitMQ Broker可以简单地看作一个RabbitMQ服务节点，或者是服务实例。

下面是Producer将消息存入RabbitMQ Broker,以及消费者从Broker中消费整个数据的流程。

![image-20201220174633723](https://raw.githubusercontent.com/znsfox/PicGo/master/img/20201220174633.png)

------

### Exchange	Types:

#### 1、fanout

fanout类型的交换器规则十分简单，它会把所有发送到该Exchange的消息路由到与它绑定的Queue中，不需要做任何判断，所以他的速度是所有交换器中最快的。**常常用来广播消息。**

#### 2、direct

direct类型的Exchange的规则也很简单，它会把消息路由到那些BindingKeyt和RoutingKey完全匹配的Queue中。

![image-20201222090116931](https://raw.githubusercontent.com/znsfox/PicGo/master/img/20201222090124.png)

direct类型的交换器常用来处理有优先级的任务，根据任务的优先级把消息发送到相应的Queue,这样可以指派更多的资源去处理优先级的任务。

#### 3、topic

topic的匹配规则基于direct，在其基础上做了相应的扩展。它约定：

RoutingKey各BindingKey为一个点号"."分隔的字符串，如：com.rabbitmq.client;

BindingKey中可以存在两种特殊的字符串，""和"#"，用于模糊匹配，前者用于匹配一个单词，后者用于匹配多个单词（包含零个）。

#### 4、headers

不推荐用这个 

------

