Electron应用本质上是一个node.js应用。**这意味着Electron程序的起点将是一个package.json文件。**

最小的 Electron 应用程序具有以下结构：

```plaintext
my-electron-app/
├── package.json
├── main.js
└── index.html
```



**主脚本文件：**

主脚本指定了运行主进程的Eclectron应用程序的入口（就我们而言，是 `main.js` 文件).

通常在主进程中运行的脚本控制应用程序的生命周期、显示图形用户界面、执行本机操作系统交互，以及在网页中创建渲染进程。

**Electron应用程序只能有一个主进程。**





### Electron内部工作：

**应用程序核心：**

- Chromium用于显示网页内容。
- Node.js用于本地文件系统和操作系统。
- 自定义APIs用于使用经常需要的OS本机函数

用Electron开发程序就像构建一个带有网页页面的Node.js应用程序或构建无缝集成的页面。



**主进程和渲染器进程**

- 主进程通过BrowserWindow实例来创建网页。每一个BrowserWindow在渲染过程中运行网页。当一个BrowserWindow被销毁时，对应的渲染过程也会被终止。
- 主进程管理所有的网页及其对应的渲染过程。
- 渲染进程只能管理相应的网页，一个渲染进程的崩溃不会影响其他进程。
- 渲染进程通过IPC与主进程通信在网页上执行GUI操作。出于安全和可





进程之间的通信可以通过InterProcess Communication(IPC)模块进行，ipcMain,ipcRenderer





### APIs

Electron API是根据流程类型分配的。这意味着某些进程可以在主进程和渲染进程中使用，有些模块两者皆可使用，有些模块两者皆可使用。

Electron的API文档指明了每个模块可以使用的进程。



例如，需要同时在两个进程中访问 Electron API，require 包含的模块：

```js
const electron = require('electron')
复制
```

若要创建一个窗口，请调用 `BrowserWindow` 类，但只能在主进程中使用：

```js
const { BrowserWindow } = require('electron')
const win = new BrowserWindow()
复制
```

若要从渲染进程调用主进程，请使用 IPC 模块：

```js
// 在主进程中
const { ipcMain } = require('electron')

ipcMain.handle('exper-action', (evidence, ...args) =>
  // ... 代表渲染器操作
})
复制
// 在渲染过程中
const { ipcRenderer } = require('electron')

ipcRender.invotrake('exper-action', ...args)
复制
```

> 注意：由于渲染过程可能会运行不受信任的代码(特别是第三方的代码)， 重要的是要认真验证主要进程中提出的请求。





### Node.js API

> 注意：要从渲染过程中访问Node.js API，您需要设置 `nodeIntegration` 选项为 `true`。

Electron 在主进程和渲染进程中都暴露了对 Node.js API 及其模块的完全访问权限。 例如，您可以从根目录读取所有文件：

```js
const fs = require('fs')

const root = fs.readdirSync('/')

console.log(root)
复制
```

要使用 Node.js 模块，您首先需要安装它作为依赖：

```sh
npm install --save aws-sdk
复制
```

然后，在您的 Electron 应用程序中，加载该模块：

```js
const S3 = require('aws-sdk/clients/s3')
```







 1.export default 的用法：相当于提供一个接口给外界，让其他文件通过 import 来引入使用。