## jQuery语法：

jQuery是通过选取HTML元素，并对选取的元素执行某些操作。

基础语法：

```js
$(selector).action()
```

- 美元符号定义 jQuery
- 选择符（selector）"查询"和"查找" HTML 元素
- jQuery 的 action() 执行对元素的操作

实例:

$(this).hide() - 隐藏当前元素

$("p").hide() - 隐藏所有段落

$("p .test").hide() - 隐藏所有 class="test" 的段落

$("#test").hide() - 隐藏所有 id="test" 的元素



### 文档就绪事件：

```js
$.(document).ready(function(){
//jquery代码
})
```

这是为了防止文档在完全加载之前就运行jquery代码。

如果文档在没有完全加载之前就运行代码，操作可能会失败。

- 试图隐藏一个不存在的元素
- 获得未完全加载的图像的大小

**简洁写法：**

```js
$(function() {
//jquery code
})
```



## jQuery选择器

jQuery基于元素的id,类，类型、属性，属性值进行“查找”（或选择）HTML元素。

**它基于已经存在的CSS选择器，除此之外，它还有一些自定义的选择器。**

jQuery 中所有选择器都以美元符号开头：$()。

示例：

### 元素选择器

jQuery 元素选择器基于元素名选取元素。

在页面中选取所有 <p> 元素:

```js
$("p")
```



### #id 选择器

jQuery #id 选择器通过 HTML 元素的 id 属性选取指定的元素。

页面中元素的 id 应该是唯一的，所以您要在页面中选取唯一的元素需要通过 #id 选择器。

通过 id 选取元素语法如下：

```js
$("#test")
```



### .class选择器

jQuery类选择器可以通过指定的class查找元素。

```js
$(".test")
```



### CSS选择器

jQuery CSS选择器可用于改变HTML元素的CSS属性。

```js
$("p").css("background-color","red");
```

### 更多实例

| 语法                     | 描述                                                    | 实例                                                         |
| :----------------------- | :------------------------------------------------------ | :----------------------------------------------------------- |
| $("*")                   | 选取所有元素                                            | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_all2) |
| $(this)                  | 选取当前 HTML 元素                                      | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_this) |
| $("p.intro")             | 选取 class 为 intro 的 <p> 元素                         | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_pclass) |
| $("p:first")             | 选取第一个 <p> 元素                                     | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_pfirst) |
| $("ul li:first")         | 选取第一个 <ul> 元素的第一个 <li> 元素                  | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_ullifirst) |
| $("ul li:first-child")   | 选取每个 <ul> 元素的第一个 <li> 元素                    | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_ullifirstchild) |
| $("[href]")              | 选取带有 href 属性的元素                                | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_hrefattr) |
| $("a[target='_blank']")  | 选取所有 target 属性值等于 "_blank" 的 <a> 元素         | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_hrefattrblank) |
| $("a[target!='_blank']") | 选取所有 target 属性值不等于 "_blank" 的 <a> 元素       | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_hrefattrnotblank) |
| $(":button")             | 选取所有 type="button" 的 <input> 元素 和 <button> 元素 | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_button2) |
| $("tr:even")             | 选取偶数位置的 <tr> 元素                                | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_even) |
| $("tr:odd")              | 选取奇数位置的 <tr> 元素                                | [在线实例](https://www.w3cschool.cn/tryrun/showhtml/tryjquery_sel_odd) |





### 独立文件中使用jQuery函数

如果您的网站包含许多页面，并且希望这些函数易于维护，那么请把您的jQuery函数放到一个单独的js文件中去。

```js
<head>
<scriptsrc="http://ajax.googleapis.com/ajax/libs/jquery/1.10.2/jquery.min.js">
</script>
<script src="my_jquery_functions.js"></script>
</head>
```





## jQuery 事件

常见 DOM 事件：

| 鼠标事件   | 键盘事件 | 表单事件 | 文档/窗口事件 |
| :--------- | :------- | :------- | :------------ |
| click      | keypress | submit   | load          |
| dblclick   | keydown  | change   | resize        |
| mouseenter | keyup    | focus    | scroll        |
| mouseleave |          | blur     | unload        |



在 jQuery 中，大多数 [DOM 事件](https://www.w3cschool.cn/htmldom/htmldom-events.html)都有一个等效的 jQuery 方法。

页面中指定一个点击事件：  

```js
$("p").click(function(){        
 // action goes here!!        
});
```





## jquery HTML

jQuery中非常重要的部分，就是操作DOM的能力。

### jquery 获取：

三个简单实用的用于DOM操作的jQuery语法：

text()-设置或者返回所选元素的文本内容。

html()-设置或者返回所选元素的内容（包括HTML标记）

val()-设置或者返回表单字段的值

attr()-用于获取属性值



### jquery添加：

- [append()](https://www.w3cschool.cn/jquery/html-append.html) - 在被选元素内部的结尾插入指定内容
- [prepend()](https://www.w3cschool.cn/jquery/html-prepend.html) - 在被选元素内部的开头插入指定内容
- [after()](https://www.w3cschool.cn/jquery/html-after.html) - 在被选元素之后插入内容
- [before()](https://www.w3cschool.cn/jquery/html-before.html) - 在被选元素之前插入内容



### 删除元素/内容

如需删除元素和内容，一般可使用以下两个 jQuery 方法：

- [remove()](https://www.w3cschool.cn/jquery/html-remove.html) - 删除被选元素（及其子元素）
- [empty()](https://www.w3cschool.cn/jquery/html-empty.html) - 从被选元素中删除子元素



### 过滤被删除的元素

jQuery remove() 方法也可接受一个参数，允许您对被删元素进行过滤。

该参数可以是任何 jQuery 选择器的语法。

下面的例子删除 class="italic" 的所有 <p> 元素：

```js
$("p").remove(".italic");
```



### jQuery 操作 CSS

jQuery 拥有若干进行 CSS 操作的方法。我们将学习下面这些：

- [addClass()](https://www.w3cschool.cn/jquery/html-addclass.html) - 向被选元素添加一个或多个类
- [removeClass()](https://www.w3cschool.cn/jquery/html-removeclass.html) - 从被选元素删除一个或多个类
- [toggleClass()](https://www.w3cschool.cn/jquery/html-toggleclass.html) - 对被选元素进行添加/删除类的切换操作
- [css()](https://www.w3cschool.cn/jquery/jquery-css.html) - 设置或返回样式属性







