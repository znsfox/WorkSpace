Quartz是一个完全由java编写的开源作业调度框架，为在java中提供作业调度提供了简单却强大的机制。

- 允许程序的开发人员根据时间的间隔来调度作业。
- 实现了作业与触发器的多对多的关系，还能把多个作业与不同的触发器关联。



### 核心概念：

1、**Job**表示一个工作，要执行的具体内容。此接口中只有一个方法，如下：

```
void execute(JobExecutionContext context) 
```

2、**JobDetail**表示 一个具体的可执行的调度任务，Job是这个具体的可执行高度程序所要执行的内容，另外JobDetail还包含了这个任务调度的方案和策略。

3、**Trigger**代表一个调度参数的配置，什么时候去调。

4、**Scheduler**代表一个调度容器，一个调度窗口中可以注册多个JobDeatil和Trigger。当Trigger与JobDetail进行组合，就可以被Scheduler进行调度了。





#### Quartz API

scheduler:	与调度程序交互的主要api,

Job:	你想要调度器执行的任务组件，需要实现的接口

JobDetail:	 用于定义作业的实例

Trigger:	触发器，定义执行给定作业的计划的组件

JobBuilder:	用于定义\构建 JobDetail实例

TriggerBuilder:	用于定义\构建 Trigger实例

scheduler:	Scheduler的生命周期，从ScheudlerFactory创建它的时候开始，到Scheduler调用shutdown()方法时结束，Scheduler被创建后，可以增加、删除和列举Job和Trigger。

但是Scheduler只有在执行start()方法时，才会真正地触发trigge,即执行job





#### Scheduler 接口：

*This is the main interface of a Quartz Scheduler.*
*A Scheduler maintains a registry of JobDetails and Triggers. Once registered, the Scheduler is responsible for executing Job s when their associated Trigger s fire (when their scheduled time arrives).*
*Scheduler instances are produced by a SchedulerFactory. A scheduler that has already been created/initialized can be found and used through the same factory that produced it. **After a Scheduler has been created, it is in "stand-by" mode, and must have its start() method called before it will fire any Jobs.***
*Jobs are to be created by the 'client program', by defining a class that implements the Job interface. **JobDetail objects** are then created (also by the client) to define a individual instances of the Job. JobDetail instances can then be registered with the Scheduler via the scheduleJob(JobDetail, Trigger) or addJob(JobDetail, boolean) method.*
*Trigger s can then be defined to fire individual Job instances based on given schedules. SimpleTrigger s are most useful for one-time firings, or firing at an exact moment in time, with N repeats with a given delay between them. CronTrigger s allow scheduling based on time of day, day of week, day of month, and month of year.*
*Jobs and Triggers have a name and group associated with them, which should uniquely identify them within a single Scheduler. The 'group' feature may be useful for creating logical groupings or categorizations of Jobs s and Triggerss. If you don't have need for assigning a group to a given Jobs of Triggers, then you can use the DEFAULT_GROUP constant defined on this interface.*
*Stored Job s can also be 'manually' triggered through the use of the triggerJob(String jobName, String jobGroup) function.*
*Client programs may also be interested in the 'listener' interfaces that are available from Quartz. The JobListener interface provides notifications of Job executions. The TriggerListener interface provides notifications of Trigger firings. **The SchedulerListener interface provides notifications of Scheduler events and errors**. Listeners can be associated with local schedulers through the ListenerManager interface.*
*The setup/configuration of a Scheduler instance is very customizable. Please consult the documentation distributed with Quartz.*
*See Also:*
*Job, JobDetail, JobBuilder, Trigger, TriggerBuilder, JobListener, TriggerListener, SchedulerListener*