## HTML DOM（文档对象模型）

当网页被加载时，浏览器会创建页面的文档对象模型。

HTML DOM定义了HTML的一系列标准的对象，以及访问和处理HTML文档的标准方法。通过DOM，你可以访问所有的HTML元素，连同它们所包含的文本和属性。

HTML独立于平台和编程语言。

**HTML DOM被称为对象的树。**

![DOM HTML tree](https://7n.w3cschool.cn/statics/images/course/pic_htmltree.gif)



通过可编程的对象模型，JavaScript获得了足够的能力来创建动态的HTML.

- JavaScript 能够改变页面中的所有 HTML 元素
- JavaScript 能够改变页面中的所有 HTML 属性
- JavaScript 能够改变页面中的所有 CSS 样式
- JavaScript 能够对页面中的所有事件做出反应



## 查找HTML元素

- 通过id.

- 通过标签名

  ```js
  var x=document.getElementById("main");
  var y=x.getElementsByTagName("p");
  ```

- 通过类名

```js
var x=document.getElementsByClassName("intro");
```



## **javascript DOM知识脑图**

![img](https://atts.w3cschool.cn/attachments/image/20160809/1470709730442234.gif)



## 改变 HTML 内容

修改HTML内容最简单的方法是使用innerHTML属性。



## 改变 HTML 属性

如需改变 HTML 元素的属性，请使用这个语法：

```js
<!DOCTYPE html>
<html>
<body>

<img id="image" src="smiley.gif">

<script>
document.getElementById("image").src="landscape.jpg";
</script>

</body>
</html>
```





## 改变 CSS

如需改变 HTML 元素的样式，请使用这个语法：    

```js
document.getElementById(*id*).style.*property*=*new style*
```

实例如下 ：

```js
<html>
<body>

<p id="p2">Hello World!</p>

<script>
document.getElementById("p2").style.color="blue";
</script>

<p>The paragraph above was changed by a script.</p>

</body>
</html>
```



## HTML DOM 事件

我们可以在事件发生时执行JavaScript。

HTML事件的例子：

- 当用户点击鼠标时
- 当网页已加载时
- 当图像已加载时
- 当鼠标移动到元素上时
- 当输入字段被改变时
- 当提交 HTML 表单时
- 当用户触发按键时



##  HTML DOM EventListener

addEventListener()方法用于向指定元素添加事件句柄(在事件发生时要执行的动作）。

addEventListener()

你可以向一个元素添加多个事件句柄。

你可以向同个元素添加多个同类型的事件句柄，如：两个 "click" 事件。

你可以向任何 DOM 对象添加事件监听，不仅仅是 HTML 元素。如： window 对象。

addEventListener() 方法可以更简单的控制事件（冒泡与捕获）。

当你使用 addEventListener() 方法时, JavaScript 从 HTML 标记中分离开来，可读性更强， 在没有控制HTML标记时也可以添加事件监听。

你可以使用 removeEventListener() 方法来移除事件的监听。

### 语法

 *element*.addEventListener(*event, function, useCapture*);

第一个参数是事件的类型 (如 "click" 或 "mousedown").

第二个参数是事件触发后调用的函数。

第三个参数是个布尔值用于描述事件是冒泡还是捕获。该参数是可选的。





## HTML DOM 元素

在DOM中，每个节点都是一个对象。

DOM节点有三个重要的属性。

nodeName:节点的名称

nodeValue:节点的值

nodeType：节点的类型

```js
<div id="div1">
<p id="p1">This is a paragraph.</p>
<p id="p2">This is another paragraph.</p>
</div>

<script>
var para=document.createElement("p");
var node=document.createTextNode("This is new.");
para.appendChild(node);

var element=document.getElementById("div1");
element.appendChild(para);
</script>
```

