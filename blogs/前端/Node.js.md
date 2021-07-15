## NodeJs基础

### 什么是JS
JS是脚本语言，脚本语言都需要一个解析器才能运行。对于写在HTML里面的JS,浏览器充当解析器的角色，而对于独立运行的JS,NodeJS就是一个解析器。

每一种解析器都是一个运行环境，不但允许JS定义各种数据结构，而且可以让JS通过环境内置的一些对象和方法做一些事情。例如运行在浏览器中的JS的用途是操作DOM，浏览器就提供了document之类的内置对象。
而运行在NodeJS中的JS的用途是操作磁盘文件和搭建HTTP服务器，因此NodeJS就提供了`fs``http`等对象。

### NodeJS的用处
NodeJS可以实现高性能web服务器，着重事件机制和异步IO模型的优越性。

### 模块
在编写稍大一些的程序时，都会将代码本地化。
在NodeJS中，一般将代码合理拆分到不同的JS的文件中。
每一个文件就是一个模块，而文件路径就是模块名

在编写模块时，有三个预定义的变量可供使用，分别是`require`,`module`,`exports`

#### require
`require`函数用于在当前模块中加载和使用别的模块，**传入一个模块名，返回一个模块导出对象。**模块名可使用相对路径（以`./`开头），或者是绝对路径（以`/`或`C:`之类的盘符开头）。另外，模块名中的`.js`扩展名可以省略。以下是一个例子。

```js
var foo1 = require('./foo');
var foo2 = require('./foo.js');
var foo3 = require('/home/user/foo');
var foo4 = require('/home/user/foo.js');

// foo1至foo4中保存的是同一个模块的导出对象。
```

加载和使用JSON文件：

```js
var data = require('./data.json');
```



#### exports

exports对象是当前模块导出对象，用于导出模块仅有方法和属性。

别的模块使用require函数得到的就是当前模块导出的exports对象。以下例子中导出了一个公有方法。

```js
exports.hello = function () {
    console.log('Hello World!');
};
```



#### module

通过module模块访问到当前模块的一些信息，但最多的就是替换当前模块的卖出对象，例如模块导出对象是一个普通对象，如果想改成一个函数的话，可以使用以下方式：

```js
module.exports = function() {
    //todo
}
```

module.exports





#### 模块初始化

一个模块的js文件仅在模块第一次被调用时执行一次，并在执行过程中初始化模块的导出对象，***之后缓存出来的导出对象被重复利用。***


#### 主模块
通过命令行参数传递给NodeJS模块以启动程序的模块被称为主模块。
主模块负责调度组成程序的其他模块完成工作。
例如：
```js
node main.js
```


#### 模块路径解析规则 

##### node_modules

NodeJS定义了一个特殊的node_modules目录用于存放模块。例如某个模块的绝对路径是/home/user/hello.js，在该模块中使用require('foo/bar')方式加载模块时，则NodeJS依次尝试使用以下路径。
```js
 /home/user/node_modules/foo/bar
 /home/node_modules/foo/bar
 /node_modules/foo/bar
```


### package
JS模块的基本单位是单个JS文件，但复杂些的模块往往由多个子模块构成。为了方便管理，我们可以把多个子模块组成的大模块称做`包（package)`，并把所有子模块放在同一个包里。

当模块的文件名是index.js，加载模块时可以使用模块所在目录的路径代替模块文件路径，因此接着上例，以下两条语句等价。
```js
var cat = require('/home/user/lib/cat');
var cat = require('/home/user/lib/cat/index');
```

### package.json
如果想自定义入口模块的文件名和存放位置，就需要在包目录下包括一个package.json文件，并在其中指定入口模块的路径。上例中的`cat`模块可以重构如下。

```json
- /home/user/lib/
    - cat/
        + doc/
        - lib/
            head.js
            body.js
            main.js
        + tests/
        package.json
```

其中`package.json`内容如下。

```json
{
    "name": "cat",
    "main": "./lib/main.js"
}
```

如此一来，就同样可以使用`require('/home/user/lib/cat')`的方式加载模块。NodeJS会根据包目录下的`package.json`找到入口模块所在位置。





## npm

npm是随同Node.js一起安装的包管理工具，能解决Node.js代码部署上的很多问题。

命令默认下载最新版三方包，如果想要下载指定版本的话，可以在包名后边加上`@<version>`，例如通过以下命令可下载0.0.1版的`argv`。

```shell
$ npm install argv@0.0.1
...
argv@0.0.1 node_modules\argv
```

NPM对`package.json`的字段做了扩展，允许在其中申明三方包依赖。因此，上边例子中的`package.json`可以改写如下：

```json
{
    "name": "node-echo",
    "main": "./lib/echo.js",
    "dependencies": {
        "argv": "0.0.2"
    }
}
```

#### 小技巧

除了本章介绍的部分外，NPM还提供了很多功能，`package.json`里也有很多其它有用的字段。除了可以在[npmjs.org/doc/](https://npmjs.org/doc/)查看官方文档外，这里再介绍一些NPM常用命令。

- NPM提供了很多命令，例如`install`和`publish`，使用`npm help`可查看所有命令。
- 使用`npm help <command>`可查看某条命令的详细帮助，例如`npm help install`。
- 在`package.json`所在目录下使用`npm install . -g`可先在本地安装当前命令行程序，可用于发布前的本地测试。
- 使用`npm update <package>`可以把当前目录下`node_modules`子目录里边的对应模块更新至最新版本。
- 使用`npm update <package> -g`可以把全局安装的对应命令行程序更新至最新版。
- 使用`npm cache clear`可以清空NPM本地缓存，用于对付使用相同版本号发布新版本代码的人。
- 使用`npm unpublish <package>@<version>`可以撤销发布自己发布过的某个版本代码。



## 文件操作：

#### 小文件拷贝

我们使用NodeJS内置的`fs`模块简单实现这个程序如下。

```js
var fs = require('fs');

function copy(src, dst) {
    fs.writeFileSync(dst, fs.readFileSync(src));
}

function main(argv) {
    copy(argv[0], argv[1]);
}

main(process.argv.slice(2));
```

 `process`是一个全局变量，可通过`process.argv`获得命令行参数。由于`argv[0]`固定等于NodeJS执行程序的绝对路径，`argv[1]`固定等于主模块的绝对路径，因此第一个命令行参数从`argv[2]`这个位置开始。

#### 大文件拷贝

上边的程序拷贝一些小文件没啥问题，但这种一次性把所有文件内容都读取到内存中后再一次性写入磁盘的方式不适合拷贝大文件，内存会爆仓。对于大文件，我们只能读一点写一点，直到完成拷贝。因此上边的程序需要改造如下。

```js
var fs = require('fs');

function copy(src, dst) {
    fs.createReadStream(src).pipe(fs.createWriteStream(dst));
}

function main(argv) {
    copy(argv[0], argv[1]);
}

main(process.argv.slice(2));
```





### API走马观花





### crypto:

Encryption module