# Spring:

### **选用哪种方式把Bean发布到Spring IoC容器中：**

1、基于约定优于配置的原则，最优先的应该是通过隐式Bean的发现机制和自动装配原则。这样做的好处是减少程序开发者的决定权，简单而又不失灵活。

2、在没有办法使用自动装配原则的情况下应该优先考虑java接口和类中实现配置，这样的好处是避免XML配置的泛滥,也更为容易。

这种场景典型的例子是一个父类有多个子类，比如学生有两个子类，男学生和女学生，通过Ioc初始化一个学生类，Ioc容器将无法知道使用哪个子类去初始化。这个时候可以使用java的注解配置来指定。

3、在上述方法都无法使用的情况下，那么只能使用XML去配置Spring IoC容器，由于在现实生活中常常要用到第三方的类库，我们无法修改里面的代码，这个时候就要通过XML的方式去配置了。

**总而言之：**当配置的类是你自身正在开发的工程，那么应该优先考虑Java配置为主，而Java配置又分为自动装配和Bean名称配置。在没有歧义的基础上，优先使用自动装配，这样就可以减少大量的XML配置。

如果所需配置的类不是你的工程开发的，那么建议使用XML的方式。



### 自动装配：

所谓的自动装配就是Sping IoC自己发现对应的Bean，自动完成装配工作的方式。



### Spring AOP:



它可以拦截一些方法，然后把各个对象组织成一个整体。

aop是通过动态代理技术，带来掌控各个对象操作的切面环境，管理包括日志，数据库事务等操作，让我们拥有可以在反射原有对象方法之前正常返回、异常返回事后插入自己逻辑代码的能力，有时候甚至可以取代原始方法。



如果可以习使用接口编程，这样的好处是可以让定义与实现分离，有利于实现变化和替换，更加灵活一些。




