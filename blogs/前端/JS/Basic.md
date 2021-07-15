## JavaScript 输出

JavaScript没有任何打印或者输出的函数。

- 使用window.alert()弹出警告框。

- 使用document.write()方法将内容写到HTML文档中。

- 使用innerHTML写入到HTML元素。

- 使用console.log()写入到浏览器的控制台。

  

## JavaScript 语句

**JavaScript语句是发送给浏览器的命令。**

这些命令的作用是告诉浏览器要做的事情。



## 对代码行进行拆行

可以在文本字符串中使用反斜杠对代码进行换行。

```js
document.write("hello! \ liqianbao")
```



## JavaScript对象

对象由花括号分割。在括号内部，对象的属性以名称和值对的形式来定义。

```js
 var person={firstname:"John", lastname:"Doe", id:5566};
```



## 常见的HTML事件

下面是一些常见的HTML事件的列表:

| 事件        | 描述                         |
| :---------- | :--------------------------- |
| onchange    | HTML 元素改变                |
| onclick     | 用户点击 HTML 元素           |
| onmouseover | 用户在一个HTML元素上移动鼠标 |
| onmouseout  | 用户从一个HTML元素上移开鼠标 |
| onkeydown   | 用户按下键盘按键             |
| onload      | 浏览器已完成页面的加载       |



## JavaScript数据类型

有5种不同的数据类型：

- string,
- number,
- boolean
- object 
- function

3种对象类型

- Object
- Date
- Array

2个不包含任何值的数据类型

- null
- undefined





## typeof操作符

你可以使用 **typeof** 操作符来查看 JavaScript 变量的数据类型。

```js
typeof "John"         // 返回 string
typeof 3.14          // 返回 number
typeof NaN           // 返回 number
typeof false         // 返回 boolean
typeof [ 1,2,3,4]       // 返回 object
typeof {name: 'John', age:34} // 返回 object
typeof new Date()       // 返回 object
typeof function () {}     // 返回 function
typeof myCar         // 返回 undefined (if myCar is not declared)
typeof null          // 返回 object
```





## 将数字转换为字符串

全局方法 **String()** 可以将数字转换为字符串。

该方法可用于任何类型的数字，字母，变量，表达式：

```js
String(x)         // 将变量 x 转换为字符串并返回
String(123)       // 将数字 123 转换为字符串并返回
String( 100+ 23)  // 将数字表达式转换为字符串并返回
```

Number 方法 **toString()** 也是有同样的效果。

```js
x.toString()
(123).toString()
(100 + 23).toString()

```



## JSON

JSON是用于存储和传输数据的格式。

**JSON通常用于服务端向网页传递数据。**



### 什么是JSON

- JSON全称为JavaScript Object Notation
- JSON是一种四星级的数据交换格式
- JSON是独立的语言
- JSON易于理解 

```text
JSON使用JavaScript语法，但JSON格式仅仅是一个文本。
文本可以被任何编程语言读取及作为数据格式传递。
```

### JSON 实例

以下文本定义了employees对象：3条员工记录（对象）的数组：

```json
{"employees":[
    {"firstName":"John", "lastName":"Doe"},
    {"firstName":"Anna", "lastName":"Smith"},
    {"firstName":"Peter", "lastName":"Jones"}
]}
```



## JSON 字符串转换为 JavaScript 对象

通常我们从服务器中获取JSON数据，并在网页中显示数据。

使用 JavaScript 内置函数 JSON.parse() 将字符串转换为 JavaScript 对象:

```js
var obj = JSON.parse(text);
```





## 函数自调用

函数表达式可以自调用，如果表达式后面紧跟括号，则会自动调用。

通过添加括号，来说明它是一个函数表达式。

```js
(function () {
    var x = "Hello!!";      // 我将调用自己
})();
```



## JavaScript函数参数

JavaScript对参数的值没有进行任何的检查。

**JavaScript与大多数语言的函数参数的区别在于：它不会关注有多少个参数被传递，不关注传递的参数的具体类型。**

函数显式参数在函数定义时列出。

函数隐藏参数(arguments)在函数调用时传递给函数真正的值。



## Arguments对象：

JavaScript函数有个内置的对象arguments对象。

通过这种方式你可以很方便的找到最后一个参数的值：

```js
x = findMax(1, 123, 500, 115, 44, 88);

function findMax() {
    var i, max = arguments[0];
    if(arguments.length < 2)return max;

    for (i = 0; i < arguments.length; i++) {
        if (arguments[i] > max) {
            max = arguments[i];
        }
    }
    return max;
}
```





## 函数作为方法调用：

在JavaScript中，你可以将函数定义为对象的方法。

以下实例创建了一个对象（myObject),对象有两个属性，firstName,lastName以及一个方法fullName();

```js
var myObject = {
    firstName:"John",
    lastName: "Doe",
    fullName: function () {
        return this.firstName + " " + this.lastName;
    }
}
myObject.fullName();         // 返回 "John Doe"
```



## 作为函数方法调用函数

在JavaScript中，函数是对象。

JavaScript有它的属性和方法。

call和apply()是预定义的函数方法。两个方法可用于调用函数，两个方法的第一个参数必须是对象本身。

```js
function myFunction(a, b) {
    return a * b;
}
myFunction.call(myObject, 10, 2);      // 返回 20
```

```js
function myFunction(a, b) {
    return a * b;
}
myArray = [10,2];
myFunction.apply(myObject, myArray);   // 返回 20
```

两个方法都使用了对象本身作为第一个参数。 两者的区别在于第二个参数： apply传入的是一个参数数组，也就是将多个参数组合成为一个数组传入，而call则作为call的参数传入（从第二个参数开始）。

在 JavaScript 严格模式(strict mode)下, 在调用函数时第一个参数会成为 **this** 的值， 即使该参数不是一个对象。

在 JavaScript 非严格模式(non-strict mode)下, 如果第一个参数的值是 null 或 undefined, 它将使用全局对象替代。

**通过 call() 或 apply() 方法你可以设置 this 的值, 且作为已存在对象的新方法调用。**



