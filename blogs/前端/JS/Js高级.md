JavaScript中所有事物都是对象：字符串，数值，数组，函数

此外，JavaScript允许自定义对象。



## 所有事物都是对象

JavaScript 提供多个内建对象，比如 String、Date、Array 等等。 对象只是带有属性和方法的特殊数据类型。

- 布尔型可以是一个对象。
- 数字型可以是一个对象。
- 字符串也可以是一个对象
- 日期是一个对象
- 数学和正则表达式也是对象
- 数组是一个对象
- 甚至函数也可以是对象



## JavaScript 对象

对象只是一种特殊的数据，对象拥有属性和方法





## async:

An async function is a function declared with the `async` keyword, and the `await` is permitted with them. The `async` and  `await` enable asynchronous, promised-based behavior to be written in a clearler style, avoiding the need to explicitly configure promise chains. 





## Standard built-in objects

The `promise` object represents the eventual completion(or failure) of an asynchronous operation and its resulting value.



## 关键字

### let

The `let` statement declares a block-scoped local variable,optionally initializing it to  a value.

```js
let x = 1;

if (x === 1) {
  let x = 2;

  console.log(x);
  // expected output: 2
}

console.log(x);
// expected output: 1

```



### const

Constants are block-scoped, much like variales declared using the `let` keyword. The value of constant can not be changed through reassignment, and it can not be redeclared.

```js
const number = 42;

try {
  number = 99;
} catch (err) {
  console.log(err);
  // expected output: TypeError: invalid assignment to const `number'
  // Note - error messages will vary depending on browser
}

console.log(number);
// expected output: 42
```

### var
The `var` statement declared a function-scoped or global-scoped variable ,optionally initializing it to a value.