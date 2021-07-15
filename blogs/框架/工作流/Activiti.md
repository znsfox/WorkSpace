Activity的开发步骤：

1、定义工作流，以图的方式

2、部署

3、执行工作流



1.1 BPMN

(Business Process model and Notation)，业务流程建模与标注，描述流程的基本符号，包括这些图元如何组成一个业务流程图，



数据库相关：

执行工作流步骤的时候会涉及到许多数据，【执行该流程的人是谁，所需要的参数是什么，包括想想看之前流程的记录等等】

Activiti会自动创建对应的数据库表,涉及的表有23个

```sql
Activiti的后台是有数据库的支持，所有的表都以ACT_开头。 第二部分是表示表的用途的两个字母标识。 用途也和服务的API对应。
ACT_RE_*: 'RE'表示repository。 这个前缀的表包含了流程定义和流程静态资源 （图片，规则，等等）。
ACT_RU_*: 'RU'表示runtime。 这些运行时的表，包含流程实例，任务，变量，异步任务，等运行中的数据。 Activiti只在流程实例执行过程中保存这些数据， 在流程结束时就会删除这些记录。 这样运行时表可以一直很小速度很快。
ACT_ID_*: 'ID'表示identity。 这些表包含身份信息，比如用户，组等等。
ACT_HI_*: 'HI'表示history。 这些表包含历史数据，比如历史流程实例， 变量，任务等等。
ACT_GE_*: 通用数据， 用于不同场景下，如存放资源文件。

```



具体开发 ：

配置数据库信息，拿到Activiti的API——Activiti引擎

代码配置工作流引擎：

```java


    @Test
    public void createActivitiEngine(){

/*        *1.通过代码形式创建
         *  - 取得ProcessEngineConfiguration对象
         *  - 设置数据库连接属性
         *  - 设置创建表的策略 （当没有表时，自动创建表）
         *  - 通过ProcessEngineConfiguration对象创建 ProcessEngine 对象*/

         //取得ProcessEngineConfiguration对象
         ProcessEngineConfiguration engineConfiguration=ProcessEngineConfiguration.
         createStandaloneProcessEngineConfiguration();
         //设置数据库连接属性
         engineConfiguration.setJdbcDriver("com.mysql.jdbc.Driver");
         engineConfiguration.setJdbcUrl("jdbc:mysql://localhost:3306/activitiDB?createDatabaseIfNotExist=true"
         + "&useUnicode=true&characterEncoding=utf8");
         engineConfiguration.setJdbcUsername("root");
         engineConfiguration.setJdbcPassword("root");


         // 设置创建表的策略 （当没有表时，自动创建表）
         //		  public static final java.lang.String DB_SCHEMA_UPDATE_FALSE = "false";//不会自动创建表，没有表，则抛异常
         //		  public static final java.lang.String DB_SCHEMA_UPDATE_CREATE_DROP = "create-drop";//先删除，再创建表
         //		  public static final java.lang.String DB_SCHEMA_UPDATE_TRUE = "true";//假如没有表，则自动创建
         engineConfiguration.setDatabaseSchemaUpdate("true");
         //通过ProcessEngineConfiguration对象创建 ProcessEngine 对象
        ProcessEngine processEngine = engineConfiguration.buildProcessEngine();
         System.out.println("流程引擎创建成功!");
        
    }

```

文件配置工作流引擎：

```java

		/**2. 通过加载 activiti.cfg.xml 获取 流程引擎 和自动创建数据库及表
		 * 
		 
		ProcessEngineConfiguration engineConfiguration=
				ProcessEngineConfiguration.createProcessEngineConfigurationFromResource("activiti.cfg.xml");
		    //从类加载路径中查找资源  activiti.cfg.xm文件名可以自定义
		ProcessEngine processEngine = engineConfiguration.buildProcessEngine();
		System.out.println("使用配置文件Activiti.cfg.xml获取流程引擎");
		*/

```

activity.cfg.xml

```xml
<beans xmlns="http://www.springframework.org/schema/beans"
	xmlns:context="http://www.springframework.org/schema/context" xmlns:tx="http://www.springframework.org/schema/tx"
	xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
	xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd
http://www.springframework.org/schema/context http://www.springframework.org/schema/context/spring-context-2.5.xsd
http://www.springframework.org/schema/tx http://www.springframework.org/schema/tx/spring-tx-3.0.xsd">
 <!-- 配置 ProcessEngineConfiguration  -->
 <bean id="processEngineConfiguration" class="org.activiti.engine.impl.cfg.StandaloneProcessEngineConfiguration">
   <!-- 配置数据库连接 -->
 <property name="jdbcDriver" value="com.mysql.jdbc.Driver"></property>
 <property name="jdbcUrl" value="jdbc:mysql://localhost:3306/activitiDB?createDatabaseIfNotExist=true&amp;useUnicode=true&amp;characterEncoding=utf8"></property>
 <property name="jdbcUsername" value="root"></property>
 <property name="jdbcPassword" value="root"></property>
 
  <!-- 配置创建表策略 :没有表时，自动创建 -->
  <property name="databaseSchemaUpdate" value="true"></property>
 
 </bean>

</beans>

```

