### ORM:

Object_Relative  DataBase-Mapping,在java对象与关系数据库之间建立某种映射，以实现直接存取java对象。

方便在关系型数据库中和类似于java等面向对象的语言进行数据转换的技术。

优点：

1. 使用业务代码访问对象，而不是数据库中的表。
2. 从面向对象的逻辑中隐藏SQL查询的细节。
3. ....



# Hibernate简介:

- Hibernate 使用 XML 文件来处理映射 Java 类别到数据库表格中，并且不用编写任何代码。
- 为在数据库中直接储存和检索 Java 对象提供简单的 APIs。
- 如果在数据库中或任何其它表格中出现变化，那么仅需要改变 XML 文件属性。
- 抽象不熟悉的 SQL 类型，并为我们提供工作中所熟悉的 Java 对象。
- Hibernate 不需要应用程序服务器来操作。
- 操控你数据库中对象复杂的关联。
- 最小化与访问数据库的智能提取策略。
- 提供简单的数据询问。



架构：

![image](https://atts.w3cschool.cn/attachments/image/wk/hibernate/hibernate_architecture.jpg)

## 配置对象:

- 数据库连接：

由Hibernate支持的一个或多个配置文件处理。这些文件是Hibernate.properties 和 hibernate.cfg.xml

- 类映射设置：

这个组件创造了Java类和数据库表格之间的联系





## SessionFactory 对象

配置对象被用于创造一个 SessionFactory 对象，使用提供的配置文件为应用程序依次配置 Hibernate，并允许实例化一个会话对象。SessionFactory 是一个线程安全对象并由应用程序所有的线程所使用。

SessionFactory 是一个重量级对象所以通常它都是在应用程序启动时创造然后留存为以后使用。每个数据库需要一个 SessionFactory 对象使用一个单独的配置文件。所以如果你使用多种数据库那么你要创造多种 SessionFactory 对象。

## Session 对象

一个会话被用于与数据库的物理连接。Session 对象是轻量级的，并被设计为每次实例化都需要与数据库的交互。持久对象通过 Session 对象保存和检索。

Session 对象不应该长时间保持开启状态因为它们通常情况下并非线程安全，并且它们应该按照所需创造和销毁。

## Transaction 对象

一个事务代表了与数据库工作的一个单元并且大部分 RDBMS 支持事务功能。在 Hibernate 中事务由底层事务管理器和事务（来自 JDBC 或者 JTA）处理。

这是一个选择性对象，Hibernate 应用程序可能不选择使用这个接口，而是在自己应用程序代码中管理事务。

## Query 对象

Query 对象使用 SQL 或者 Hibernate 查询语言（HQL）字符串在数据库中来检索数据并创造对象。一个查询的实例被用于连结查询参数，限制由查询返回的结果数量，并最终执行查询。

# Hibernate 配置



## Hibernate 属性

下面是一个重要的属性列表，你可能需要表中的属性来在单独的情况下配置数据库。

| **S.N.** | **属性和描述**                                               |
| :------- | :----------------------------------------------------------- |
| 1        | **hibernate.dialect** 这个属性使 Hibernate 应用为被选择的数据库生成适当的 SQL。 |
| 2        | **hibernate.connection.driver_class** JDBC 驱动程序类。      |
| 3        | **hibernate.connection.url** 数据库实例的 JDBC URL。         |
| 4        | **hibernate.connection.username** 数据库用户名。             |
| 5        | **hibernate.connection.password** 数据库密码。               |
| 6        | **hibernate.connection.pool_size** 限制在 Hibernate 应用数据库连接池中连接的数量。 |
| 7        | **hibernate.connection.autocommit** 允许在 JDBC 连接中使用自动提交模式。 |



# Hibernate 会话

Session用于获取与数据库的物理连接。Session对象是轻量级的，并且设计为在每次需要与数据库进行交互时被实例化。

持久态对象被保存，并通过Session对象检索找回。

该 Session 对象不应该长时间保持开放状态，因为它们通常不能保证线程安全，而应该根据需求被创建和销毁。Session 的主要功能是为映射实体类的实例提供创建，读取和删除操作。这些实例可能在给定时间点时存在于以下三种状态之一：

- **瞬时状态**: 一种新的持久性实例，被 Hibernate 认为是瞬时的，它不与 Session 相关联，在数据库中没有与之关联的记录且无标识符值。

- **持久状态**：可以将一个瞬时状态实例通过与一个 Session 关联的方式将其转化为持久状态实例。持久状态实例在数据库中没有与之关联的记录，有标识符值，并与一个 Session 关联。

- **脱管状态**：一旦关闭 Hibernate Session，持久状态实例将会成为脱管状态实例。

  

  若 Session 实例的持久态类别是序列化的，则该 Session 实例是序列化的。一个典型的事务应该使用以下语法：

  ```
  Session session = factory.openSession();
  Transaction tx = null;
  try {
     tx = session.beginTransaction();
     // do some work
     ...
     tx.commit();
  }
  catch (Exception e) {
     if (tx!=null) tx.rollback();
     e.printStackTrace(); 
  }finally {
     session.close();
  }
  ```

  如果 Session 引发异常，则事务必须被回滚，该 session 必须被丢弃。

# Hibernate 持久化类

## 持久化类

Hibernate 的完整概念是提取 Java 类属性中的值，并且将它们保存到数据库表单中。映射文件能够帮助 Hibernate 确定如何从该类中提取值，并将它们映射在表格和相关域中。

在 Hibernate 中，其对象或实例将会被存储在数据库表单中的 Java 类被称为持久化类。若该类遵循一些简单的规则或者被大家所熟知的 Plain Old Java Object (POJO) 编程模型，Hibernate 将会处于其最佳运行状态。以下所列就是持久化类的主要规则，然而，在这些规则中，没有一条是硬性要求。

- 所有将被持久化的 Java 类都需要一个默认的构造函数。
- 为了使对象能够在 Hibernate 和数据库中容易识别，所有类都需要包含一个 ID。此属性映射到数据库表的主键列。
- 所有将被持久化的属性都应该声明为 private，并具有由 JavaBean 风格定义的 **getXXX** 和 **setXXX** 方法。
- Hibernate 的一个重要特征为代理，它取决于该持久化类是处于非 final 的，还是处于一个所有方法都声明为 public 的接口。
- 所有的类是不可扩展或按 EJB 要求实现的一些特殊的类和接口。

POJO 的名称用于强调一个给定的对象是普通的 Java 对象，而不是特殊的对象，尤其不是一个 Enterprise JavaBean。

# Hibernate 映射文件

## 映射文件

一个对象/关系型映射一般定义在 XML 文件中。映射文件指示 Hibernate 如何将已经定义的类或类组与数据库中的表对应起来。

尽管有些 Hibernate 用户选择手写 XML 文件，但是有很多工具可以用来给先进的 Hibernate 用户生成映射文件。这样的工具包括 **XDoclet**, **Middlegen** 和 **AndroMDA**。

让我们来考虑我们之前定义的 POJO 类，它的对象将延续到下一部分定义的表中。

# Hibernate 映射类型

## 映射类型

当你准备一个 Hibernate 映射文件时，我们已经看到你把 Java 数据类型映射到了 RDBMS 数据格式。在映射文件中已经声明被使用的 **types** 不是 Java 数据类型；它们也不是 SQL 数据库类型。这种类型被称为 Hibernate 映射类型，可以从 Java 翻译成 SQL，反之亦然。

在这一章中列举出所有的基础，日期和时间，大型数据对象，和其它内嵌的映射数据类型。

## 原始类型

| 映射类型    | Java 类型                    | ANSI SQL 类型        |
| :---------- | :--------------------------- | :------------------- |
| integer     | int 或 java.lang.Integer     | INTEGER              |
| long        | long 或 java.lang.Long       | BIGINT               |
| short       | short 或 java.lang.Short     | SMALLINT             |
| float       | float 或 java.lang.Float     | FLOAT                |
| double      | double 或 java.lang.Double   | DOUBLE               |
| big_decimal | java.math.BigDecimal         | NUMERIC              |
| character   | java.lang.String             | CHAR(1)              |
| string      | java.lang.String             | VARCHAR              |
| byte        | byte 或 java.lang.Byte       | TINYINT              |
| boolean     | boolean 或 java.lang.Boolean | BIT                  |
| yes/no      | boolean 或 java.lang.Boolean | CHAR(1) ('Y' or 'N') |
| true/false  | boolean 或 java.lang.Boolean | CHAR(1) ('T' or 'F') |

## 日期和时间类型

| 映射类型      | Java 类型                            | ANSI SQL 类型 |
| :------------ | :----------------------------------- | :------------ |
| date          | java.util.Date 或 java.sql.Date      | DATE          |
| time          | java.util.Date 或 java.sql.Time      | TIME          |
| timestamp     | java.util.Date 或 java.sql.Timestamp | TIMESTAMP     |
| calendar      | java.util.Calendar                   | TIMESTAMP     |
| calendar_date | java.util.Calendar                   | DATE          |

## 二进制和大型数据对象

| 映射类型     | Java 类型                                           | ANSI SQL 类型       |
| :----------- | :-------------------------------------------------- | :------------------ |
| binary       | byte[]                                              | VARBINARY (or BLOB) |
| text         | java.lang.String                                    | CLOB                |
| serializable | any Java class that implements java.io.Serializable | VARBINARY (or BLOB) |
| clob         | java.sql.Clob                                       | CLOB                |
| blob         | java.sql.Blob                                       | BLOB                |

## JDK 相关类型

| 映射类型 | Java 类型          | ANSI SQL 类型 |
| :------- | :----------------- | :------------ |
| class    | java.lang.Class    | VARCHAR       |
| locale   | java.util.Locale   | VARCHAR       |
| timezone | java.util.TimeZone | VARCHAR       |
| currency | java.util.Currency | VARCHAR       |













https://www.w3cschool.cn/hibernate/86go1ie3.html