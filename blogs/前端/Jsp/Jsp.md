# JSP简介：

Java Server Pages,是一种动态网页开发技术。它使用JSP标签在HTML网页中插入Java代码。

JSP是一种Java servlet,主要用户实现Java web应用程序的用户界面部分。通常结合HTML、XHTML、XML元素以及嵌入JSP操作和命令来编写JSP。



JSP通过网页表彰来获取用户输入数据，访问数据库以及其他数据源，然后动态地创建网页。

jsp有多种功能，比如访问数据库，记录用户选择信息，访问javaBeans组件等，还可以在不同的网页组件中传递控制信息和共享信息。









# JSP 结构

网络服务器需要一个Jsp引擎,也就是一个容器来处理JSP页面。

容器负责截获对JSP页面的请求。

JSP容器与Web服务器协同合作，为JSP的正常运行提供必要的运行环境和其他服务，并且能够正确识别专属于JSP网页的特殊元素。

下图显示了JSP容器和JSP文件在Web应用中所处的位置。

![img](https://7n.w3cschool.cn/statics/images/course/jsp-arch.jpg)

## JSP处理

以下步骤表明了Web服务器是如何使用JSP来创建网页的：

- 就像其他普通的网页一样，您的浏览器发送一个HTTP请求给服务器。
- Web服务器识别出这是一个对JSP网页的请求，并且将该请求传递给JSP引擎。通过使用URL或者.jsp文件来完成。
- JSP引擎从磁盘中载入JSP文件，然后将它们转化为servlet。这种转化只是简单地将所有模板文本改用println()语句，并且将所有的JSP元素转化成Java代码。
- JSP引擎将servlet编译成可执行类，并且将原始请求传递给servlet引擎。
- Web服务器的某组件将会调用servlet引擎，然后载入并执行servlet类。在执行过程中，servlet产生HTML格式的输出并将其内嵌于HTTP response中上交给Web服务器。
- Web服务器以静态HTML网页的形式将HTTP response返回到您的浏览器中。
- 最终，Web浏览器处理HTTP response中动态产生的HTML网页，就好像在处理静态网页一样。

以上提及到的步骤可以用下图来表示：

![img](https://atts.w3cschool.cn/attachments/day_160825/201608251727372798.jpg)

一般情况下，JSP引擎会检查JSP文件对应的servlet是否已经存在，并且检查JSP文件的修改日期是否早于servlet。如果JSP文件的修改日期早于对应的servlet，那么容器就可以确定JSP文件没有被修改过并且servlet有效。这使得整个流程与其他脚本语言（比如PHP）相比要高效快捷一些。

总的来说，JSP网页就是用另一种方式来编写servlet而不用成为Java编程高手。除了解释阶段外，JSP网页几乎可以被当成一个普通的servlet来对待。









# JSP语法：

## jsp脚本程序：

脚本程序中可以包含任意量的Java语句，变量，方法或表达式，只要它们在脚本语言中是有效的。

```
<% 代码片段 %>
```



## jsp声明：

一个声明可以声明一个或多个变量、方法，供后面的java代码使用。在jsp文件中，你必须先声明这些变量和方法才能使用它们。

JSP声明的语法格式：

```
<%! declaration; [ declaration; ]+ ... %>
```



## jsp表达式：

一个JSP表达式中包含的脚本语言表达式，先被转化成String,然后插入到表达式出现的地方。

由于表达式的值会被转化成String,所以可以在一个文本行中使用表达式而不用管它是否是HTML标签。

**表达式元素中可以包含任何符合java语言的表达式，但不能使用分号来结束表达式。**

程序示例：

```
<html> 
<head>
<title>A Comment Test</title>
</head> 
<body>
<p>   
  Today's date: <%= (new java.util.Date()).toLocaleString()%>
</p>
</body> 
</html> 
```



## JSP指令

jsp指定用来设置与整个jsp页面相关的属性。

JSP指令语法格式：

```
<%@ directive attribute="value" %>
```

这里有三种指令标签：

| **指令**           | **描述**                                                  |
| :----------------- | :-------------------------------------------------------- |
| <%@ page ... %>    | 定义页面的依赖属性，比如脚本语言、error页面、缓存需求等等 |
| <%@ include ... %> | 包含其他文件                                              |
| <%@ taglib ... %>  | 引入标签库的定义，可以是自定义标签                        |



## JSP行为

jsp行为标签使用xml语法结构来控制servlet引擎。它能够动态插入一个文件，重用JavaBean组件，引导用户去另一个界面，为java插件产生相关的HTML等等。

行为标签只有一个语法格式，它严格遵循XML标准。

```
<jsp:action_name attribute="value"/>
```

行为标签基本上是一些预先就定义好的函数。

下表罗列出了一些可用的JSP行为标签：：

| **语法**        | **描述**                                                   |
| :-------------- | :--------------------------------------------------------- |
| jsp:include     | 用于在当前页面中包含静态或动态资源                         |
| jsp:useBean     | 寻找和初始化一个JavaBean组件                               |
| jsp:setProperty | 设置 JavaBean组件的值                                      |
| jsp:getProperty | 将 JavaBean组件的值插入到 output中                         |
| jsp:forward     | 从一个JSP文件向另一个文件传递一个包含用户请求的request对象 |
| jsp:plugin      | 用于在生成的HTML页面中包含Applet和JavaBean对象             |
| jsp:element     | 动态创建一个XML元素                                        |
| jsp:attribute   | 定义动态创建的XML元素的属性                                |
| jsp:body        | 定义动态创建的XML元素的主体                                |
| jsp:text        | 用于封装模板数据                                           |



## JSP隐含对象

JSP支持九个自动定义的变量，江湖人称隐含对象。这九个隐含对象的简介见下表：

| **对象**    | **描述**                                                     |
| :---------- | :----------------------------------------------------------- |
| request     | **HttpServletRequest**类的实例                               |
| response    | **HttpServletResponse**类的实例                              |
| out         | **PrintWriter**类的实例，用于把结果输出至网页上              |
| session     | **HttpSession**类的实例                                      |
| application | **ServletContext**类的实例，与应用上下文有关                 |
| config      | **ServletConfig**类的实例                                    |
| pageContext | **PageContext**类的实例，提供对JSP页面所有对象以及命名空间的访问 |
| page        | 类似于Java类中的this关键字                                   |
| Exception   | **Exception**类的对象，代表发生错误的JSP页面中对应的异常对象 |



## JSP运算符：

JSP支持所有Java逻辑和算术运算符。

下表罗列出了JSP常见运算符，优先级从高到底：

| **类别**  | **操作符**                         | **结合性** |
| :-------- | :--------------------------------- | :--------- |
| 后缀      | () [] . (点运算符)                 | 左到右     |
| 一元      | ++ - - ! ~                         | 右到左     |
| 可乘性    | * / %                              | 左到右     |
| 可加性    | + -                                | 左到右     |
| 移位      | >> >>> <<                          | 左到右     |
| 关系      | > >= < <=                          | 左到右     |
| 相等/不等 | == !=                              | 左到右     |
| 位与      | &                                  | 左到右     |
| 位异或    | ^                                  | 左到右     |
| 位或      | \|                                 | 左到右     |
| 逻辑与    | &&                                 | 左到右     |
| 逻辑或    | \|\|                               | 左到右     |
| 条件判断  | ?:                                 | 右到左     |
| 赋值      | = += -= *= /= %= >>= <<= &= ^= \|= | 右到左     |
| 逗号      | ,                                  | 左到右     |



## JSP常量

JSP语言定义了以下几个常量：

- 布尔值(boolean)：true 和 false；
- 整型(int)：与Java中的一样;
- 浮点型(float)：与Java中的一样;
- 字符串(string)：以单引号或双引号开始和结束；
- Null：null。



# JSP指令：

jsp指令用来设置整个jsp页面相关的属性，如网页的编码方式和脚本语言。

语法格式如下 ：

```
<%@ directive attribute="value" %>
```

指令可以有很多个属性，它们以键值对的形式存在，并用逗号隔开。

JSP中的三种指令标签：

| **指令**           | **描述**                                                |
| :----------------- | :------------------------------------------------------ |
| <%@ page ... %>    | 定义网页依赖属性，比如脚本语言、error页面、缓存需求等等 |
| <%@ include ... %> | 包含其他文件                                            |
| <%@ taglib ... %>  | 引入标签库的定义                                        |



## page指令：

page指令为窗口提供当前页面的使用说明。一个jsp页面可以包含多个page指令。

page指令的语法格式：

```
<%@ page attribute="value" %>
```

属性：

下表列出与Page指令相关的属性：

| **属性**           | **描述**                                            |
| :----------------- | :-------------------------------------------------- |
| buffer             | 指定out对象使用缓冲区的大小                         |
| autoFlush          | 控制out对象的 缓存区                                |
| contentType        | 指定当前JSP页面的MIME类型和字符编码                 |
| errorPage          | 指定当JSP页面发生异常时需要转向的错误处理页面       |
| isErrorPage        | 指定当前页面是否可以作为另一个JSP页面的错误处理页面 |
| extends            | 指定servlet从哪一个类继承                           |
| import             | 导入要使用的Java类                                  |
| info               | 定义JSP页面的描述信息                               |
| isThreadSafe       | 指定对JSP页面的访问是否为线程安全                   |
| language           | 定义JSP页面所用的脚本语言，默认是Java               |
| session            | 指定JSP页面是否使用session                          |
| isELIgnored        | 指定是否执行EL表达式                                |
| isScriptingEnabled | 确定脚本元素能否被使用                              |



## include指令：

JSP可以通过include来包含其他文件，被包含的文件可以是JSP文件、HTML文件，或者是文本文件，包含的文件会成为JSP文件的一部分，会被同时编译执行。

include的语法格式如下：

```
<@ include file="relative url" %>
```

include的指令中的文件名实际上是一个相对URL。如果没有给文件夹一个路径，JSP编译器默认在当前路径下寻找。



Taglib指令：

JSP API允许用户自定义标签，一个自定义标签为就是自定义标签的集合。

Taglib指令引入一个自定义标签的定义，包括库路径，自定义标签。

Taglib指令的语法：

```
<%@ taglib uri="uri" prefix="prefixOfTag" %>
```

uri属性确定标签库的位置，prefix属性指定标签库的前缀。



# JSP 动作元素

与jsp指令元素不同的是，jsp动作元素在指定阶段起作用。

JSP动作元素是用XML语法写成的。利用JSP动作可以动态地插入文件，重用Java Bean的组件，把用户定向到外面的组件中去，为java插件生成HTML代码。

动作元素只有一个语法，它符合XML标准：

```
<jsp:action_name attribute="value"/>
```

动作元素基本上都是预定义的函数，JSP规范定义了一系列的标准动作，它用JSP作为前缀，可用的标准动作元素如下：

| 语法            | 描述                                            |
| :-------------- | :---------------------------------------------- |
| jsp:include     | 在页面被请求的时候引入一个文件。                |
| jsp:useBean     | 寻找或者实例化一个JavaBean。                    |
| jsp:setProperty | 设置JavaBean的属性。                            |
| jsp:getProperty | 输出某个JavaBean的属性。                        |
| jsp:forward     | 把请求转到一个新的页面。                        |
| jsp:plugin      | 根据浏览器类型为Java插件生成OBJECT或EMBED标记。 |
| jsp:element     | 定义动态XML元素                                 |
| jsp:attribute   | 设置动态定义的XML元素属性。                     |
| jsp:body        | 设置动态定义的XML元素内容。                     |
| jsp:text        | 在JSP页面和文档中使用写入文本的模板             |

***常见的属性：***

所有的动作要素都有两个属性：**id, 	scope**

- id:

id属性是动作元素的唯一标识，可以在JSP页面中引用。动作元素创建的id值可以通过PageContext来调用。

- scope:

该属性用于识别动作元素的生命周期。

id属性和scope属性有直接关系，scope属性定义了相关联id对象的寿命。scope属性有四个可能的值：1.page 	2.request	3.session	4.application



## <jsp:include>动作元素

<jsp:include>动作元素用来包含静态和动态的文件。该动作把指定文件插入正在生成的页面。语法格式如下：

```
<jsp:include page="relative URL" flush="true" />
```

　前面已经介绍过include指令，它是在JSP文件被转换成Servlet的时候引入文件，而这里的jsp:include动作不同，插入文件的时间是在页面被请求的时候。

以下是include动作相关的属性列表。

| 属性  | 描述                                       |
| :---- | :----------------------------------------- |
| page  | 包含在页面中的相对URL地址。                |
| flush | 布尔属性，定义在包含资源前是否刷新缓存区。 |

### 实例

以下我们定义了两个文件date.jsp和main.jsp，代码如下所示：

date.jsp文件代码：

```jsp
<p>
   Today's date: <%= (new java.util.Date()).toLocaleString()%>
</p>
```

main.jsp文件代码：

```jsp
<html>
<head>
<title>The include Action Example</title>
</head>
<body>
<center>
<h2>The include action Example</h2>
<jsp:include page="date.jsp" flush="true" />
</center>
</body>
</html>
```

现在将以上两个文件放在服务器的根目录下，访问main.jsp文件。显示结果如下：

```
The include action Example
Today's date: 12-Sep-2013 14:54:22
```



## <jsp:useBean>动作元素：

jsp:useBean用来装载一个将在jsp页面中使用的JavaBean。

这个功能非常有用，因为它可以使我们即可以发挥java组件重用的优势，也避免了损失JSP区别Servlet的方便性。

jsp:useBean动作最简单的语法为：

```jsp
<jsp:userBean id="name" class="package.class"/>	
```

在类载入后，我们既可以通过 jsp:setProperty 和 jsp:getProperty 动作来修改和检索bean的属性。

以下是useBean动作相关的属性列表。

| 属性     | 描述                                                        |
| :------- | :---------------------------------------------------------- |
| class    | 指定Bean的完整包名。                                        |
| type     | 指定将引用该对象变量的类型。                                |
| beanName | 通过 java.beans.Beans 的 instantiate() 方法指定Bean的名字。 |

在给出具体实例前，让我们先来看下 jsp:setProperty 和 jsp:getProperty 动作元素：

------

### <jsp:setProperty>动作元素

　jsp:setProperty用来设置已经实例化的Bean对象的属性，有两种用法。首先，你可以在jsp:useBean元素的外面（后面）使用jsp:setProperty，如下所示：

```jsp
<jsp:useBean id="myName" ... />
...
<jsp:setProperty name="myName" property="someProperty" .../>
```

　此时，不管jsp:useBean是找到了一个现有的Bean，还是新创建了一个Bean实例，jsp:setProperty都会执行。第二种用法是把jsp:setProperty放入jsp:useBean元素的内部，如下所示：

```jsp
<jsp:useBean id="myName" ... >
...
   <jsp:setProperty name="myName" property="someProperty" .../>
</jsp:useBean>
```

此时，jsp:setProperty只有在新建Bean实例时才会执行，如果是使用现有实例则不执行jsp:setProperty。

| 属性     | 描述                                                         |
| :------- | :----------------------------------------------------------- |
| name     | name属性是必需的。它表示要设置属性的是哪个Bean。             |
| property | property属性是必需的。它表示要设置哪个属性。有一个特殊用法：如果property的值是"*"，表示所有名字和Bean属性名字匹配的请求参数都将被传递给相应的属性set方法。 |
| value    | value 属性是可选的。该属性用来指定Bean属性的值。字符串数据会在目标类中通过标准的valueOf方法自动转换成数字、boolean、Boolean、 byte、Byte、char、Character。例如，boolean和Boolean类型的属性值（比如"true"）通过 Boolean.valueOf转换，int和Integer类型的属性值（比如"42"）通过Integer.valueOf转换。 　　value和param不能同时使用，但可以使用其中任意一个。 |
| param    | param 是可选的。它指定用哪个请求参数作为Bean属性的值。如果当前请求没有参数，则什么事情也不做，系统不会把null传递给Bean属性的set方法。因此，你可以让Bean自己提供默认属性值，只有当请求参数明确指定了新值时才修改默认属性值。 |

------

### <jsp:getProperty>动作元素

　jsp:getProperty动作提取指定Bean属性的值，转换成字符串，然后输出。语法格式如下：

```
<jsp:useBean id="myName" ... />
...
<jsp:getProperty name="myName" property="someProperty" .../>
```

下表是与getProperty相关联的属性：

| 属性     | 描述                                   |
| :------- | :------------------------------------- |
| name     | 要检索的Bean属性名称。Bean必须已定义。 |
| property | 表示要提取Bean属性的值                 |



## <jsp:forward> 动作元素

jsp:forward动作把请求转到另外的界面。其只有一个属性page。

语法格式如下：

```jsp
<jsp:forward page="Relative URL" />
```

以下是forward相关联的属性：

| 属性 | 描述                                                         |
| :--- | :----------------------------------------------------------- |
| page | page属性包含的是一个相对URL。page的值既可以直接给出，也可以在请求的时候动态计算，可以是一个JSP页面或者一个 Java Servlet. |







## <jsp:plugin>动作元素



jsp:plugin动作用来根据浏览器的类型，插入通过Java插件 运行Java Applet所必需的OBJECT或EMBED元素。

如果需要的插件不存在，它会下载插件，然后执行Java组件。 Java组件可以是一个applet或一个JavaBean。

plugin动作有多个对应HTML元素的属性用于格式化Java 组件。param元素可用于向Applet 或 Bean 传递参数。

以下是使用plugin 动作元素的典型实例:

```jsp
<jsp:plugin type="applet" codebase="dirname" code="MyApplet.class"                            width="60" height="80">
   <jsp:param name="fontcolor" value="red" />
   <jsp:param name="background" value="black" />
 
   <jsp:fallback>
      Unable to initialize Java Plugin
   </jsp:fallback>
 
</jsp:plugin>
```

如果你有兴趣可以尝试使用applet来测试jsp:plugin动作元素，<fallback>元素是一个新元素，在组件出现故障的错误是发送给用户错误信息。



## <jsp:element> 、 <jsp:attribute>、 <jsp:body>动作元素

jsp:element, jsp:attribute, jsp:body 动作元素动态定义XML元素。动态是非常重要的，这意味着xml元素在编译时是动态生成的而非静态。

以下实例动态定义了XML元素：

```xml
<%@page language="java" contentType="text/html"%>
<html xmlns="http://www.w3c.org/1999/xhtml"       xmlns:jsp="http://java.sun.com/JSP/Page">

<head><title>Generate XML Element</title></head>
<body>
<jsp:element name="xmlElement">
<jsp:attribute name="xmlElementAttr">
   Value for the attribute
</jsp:attribute>
<jsp:body>
   Body for XML element
</jsp:body>
</jsp:element>
</body>
</html>
```

执行时生成HTML代码如下：

```html
<html xmlns="http://www.w3c.org/1999/xhtml"       xmlns:jsp="http://java.sun.com/JSP/Page">
 
<head><title>Generate XML Element</title></head>
<body>
<xmlElement xmlElementAttr="Value for the attribute">
   Body for XML element
</xmlElement>
</body>
</html>
```





## <jsp:text>动作元素

jsp:text 动作元素允许在JSP页面和文档中使用写入文档的模板，语法格式如下：

```jsp
<jsp:text>template data<jsp:text>
```

**以上文本模板不能包含其他元素，只能包含文本和EL表达式。**

以上文本模板不能包含其他元素，只能只能包含文本和EL表达式（注：EL表达式将在后续章节中介绍）。请注意，在XML文件中，您不能使用表达式如 ${whatever > 0}，因为>符号是非法的。 你可以使用 ${whatever gt 0}表达式或者嵌入在一个CDATA部分的值。

```
<jsp:text><![CDATA[<br>]]></jsp:text>
```

如果你需要在 XHTML 中声明 DOCTYPE,必须使用到<jsp:text>动作元素，实例如下：

```
<jsp:text><![CDATA[<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "DTD/xhtml1-strict.dtd">]]>
</jsp:text>
<head><title>jsp:text action</title></head>
<body>

<books><book><jsp:text>  
    Welcome to JSP Programming
</jsp:text></book></books>

</body>
</html>
```

你可以对以上实例尝试使用<jsp:text>及不使用该动作元素执行结果的区别。



# JSP 隐式对象

JSP隐式对象是JSP容器为每个页面提供的Java对象，开发者可以直接使用它们而不用显式声明。JSP隐式对象也被称为预定义变量。

JSP所支持的九大隐式对象：

| **对象**    | **描述**                                                     |
| :---------- | :----------------------------------------------------------- |
| request     | **HttpServletRequest**类的实例                               |
| response    | **HttpServletResponse**类的实例                              |
| out         | **PrintWriter**类的实例，用于把结果输出至网页上              |
| session     | **HttpSession**类的实例                                      |
| application | **ServletContext**类的实例，与应用上下文有关                 |
| config      | **ServletConfig**类的实例                                    |
| pageContext | **PageContext**类的实例，提供对JSP页面所有对象以及命名空间的访问 |
| page        | 类似于Java类中的this关键字                                   |
| Exception   | **Exception**类的对象，代表发生错误的JSP页面中对应的异常对象 |



## request:

request是javax.servlet.http.HttpServletRequest类的实例。每当用户请求一个JSP页面时，JSP引擎应付制造一个新的request对象来代表这个请求。

request对象提供了一系列方法来获取HTTP头信息，cookies,HTTP方法等等。



## response对象：

response对象是javax.servlet.http.HttpServletResponse类的实例。当服务器创建request对象时，会同时创建用于响应这个客户端的response对象。





# JSP 客户端请求

当浏览器请求一个网页时，它会向网络服务器发送一系列不能被直接读取的信息，因为这些信息是作为HTTP信息头的一部分来传送的。

下表列出了浏览器端信息头的一些重要内容，在以后的网络编程中将会经常见到这些信息：

| **信息**            | **描述**                                                     |
| :------------------ | :----------------------------------------------------------- |
| Accept              | 指定浏览器或其他客户端可以处理的MIME类型。它的值通常为 **image/png** 或 **image/jpeg** |
| Accept-Charset      | 指定浏览器要使用的字符集。比如 ISO-8859-1                    |
| Accept-Encoding     | 指定编码类型。它的值通常为 **gzip** 或**compress**           |
| Accept-Language     | 指定客户端首选语言，servlet会优先返回以当前语言构成的结果集，如果servlet支持这种语言的话。比如 en，en-us，ru等等 |
| Authorization       | 在访问受密码保护的网页时识别不同的用户                       |
| Connection          | 表明客户端是否可以处理HTTP持久连接。持久连接允许客户端或浏览器在一个请求中获取多个文件。**Keep-Alive** 表示启用持久连接 |
| Content-Length      | 仅适用于POST请求，表示 POST 数据的字节数                     |
| Cookie              | 返回先前发送给浏览器的cookies至服务器                        |
| Host                | 指出原始URL中的主机名和端口号                                |
| If-Modified-Since   | 表明只有当网页在指定的日期被修改后客户端才需要这个网页。 服务器发送304码给客户端，表示没有更新的资源 |
| If-Unmodified-Since | 与If-Modified-Since相反， 只有文档在指定日期后仍未被修改过，操作才会成功 |
| Referer             | 标志着所引用页面的URL。比如，如果你在页面1，然后点了个链接至页面2，那么页面1的URL就会包含在浏览器请求页面2的信息头中 |
| User-Agent          | 用来区分不同浏览器或客户端发送的请求，并对不同类型的浏览器返回不同的内容 |

------

## HttpServletRequest类

request是javax.servlet.http.HttpServletRequest类的实例。

每当客户端请求一个页面时，JSP引擎就会产生一个新的对象来代表这个请求。

request







https://www.w3cschool.cn/jsp/jsp-syntax.html