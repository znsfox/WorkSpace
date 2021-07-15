<!-- 生产环境版本，优化了尺寸和速度 --> <script src="https://cdn.jsdelivr.net/npm/vue"></script>



## 声明式渲染：

Vue.js的核心是一个允许采用简洁的模板语法来声明式地将数据 渲染进DOM的系统。

### 文本插入：

```html
<div id="app">   {{ message }} </div>
```

```js
var app = new Vue({  el: '#app',  data: {    message: 'Hello Vue!'  } })
```

数据和DOM会被建立关联，所有东西都响应式的，打开浏览器的JS控制台，修改相应的data，就能看到示例的更新。



这将不再和HTML直接交互，一个Vue应用会将其挂载到一个DOM元素上，然后对其进行文档控制。HTML是我们的入口，其余的都会发生在新创建的vue实例内。



### 绑定元素attribute:

```html
<div id="app-2">
  <span v-bind:title="message">
    鼠标悬停几秒钟查看此处动态绑定的提示信息！
  </span>
</div>
```

```js
var app2 = new Vue({  
    el: '#app-2', 
    data: {    message: '页面加载于 ' + new Date().toLocaleString() 
          } })
```

**v-bind** attribute被称为**指令**。指令带有前缀v-,以表示它们是Vue提供的特殊attribute,它们会在渲染的DOM上应用特殊的响应式行为，在本例中，它的意思是：

将这个元素的`title`  attribute和Vue实例的`message` property保持一致。





### 条件与循环：

控制切换一个元素是否显示也相当简单：

```html
<div id="app-3" >
    <p v-if="seen">
        现在你看到我了
    </p>
</div>
```

```js
var app3 = new Vue({
el:'app-3',
data: {
    seen:true
}
})
```



不仅可以把数据绑定到DOM文本或attribute,也可以绑定到DOM结构。此外，vue也提供一个强大的过滤系统，可以在veu进行插入，更新或移除元素时自动应用过滤效果。



还有其它很多指令，每个都有特殊的功能。例如，`v-for` 指令可以绑定数组的数据来渲染一个项目





### 处理用户输入

我们可以用`v-on`指令添加一个事件监听器，通过它调用在Vue实例中的方法。



所有的DOM操作都由Vue来处理，编写的代码只需要关注逻辑层面即可

vue还提供了`v-model`,它能轻松实现表彰输入和应用状态之间的双向绑定。





### 组件化应用构建

组件系统是Vue的另一个重要概念，因为它是一种抽象，允许我们使用小型、独立和通常可利用的组件构建大型应用。

几乎任意类型的应用界面都可以抽你成一个组件树。

<img src="https://cn.vuejs.org/images/components.png" alt="Component Tree" style="zoom: 67%;" /> 在vue里，一个组件本质上是一个拥有预定义选项的Vue实例。在Vue中注册组件很简单：



可以从父作用域将数据传到子组件。



**在一个大型应用中，有必要将整个应用划分为组件，以使开发更易管理。**

这里有一个 (假想的) 例子，以展示使用了组件的应用模板是什么样的：

```html
<div id="app">
  <app-nav></app-nav>
  <app-view>
    <app-sidebar></app-sidebar>
    <app-content></app-content>
  </app-view>
</div>
```





Vue组件非常类似于自定义元素--它是**web组件规范**的一部分，这是因为Vue的组件语法部分参考了该规范，例如Vue组件实现了Slot API与`is `  attribute,但是还有几个关键差别：

- Web Components无法已经完成并通过，但未被所有浏览器原生实现，目前 Safari 10.1+、Chrome 54+ 和 Firefox 63+ 原生支持 Web Components。相比之下，Vue 组件不需要任何 polyfill，并且在所有支持的浏览器 (IE9 及更高版本) 之下表现一致。必要时，Vue 组件也可以包装于原生自定义元素之内。
- Vue组件提供了纯自定义的元素所不具备的一些重要功能，最突出的是**跨组件数据流**，**自定义事件通信**以及**构建工具集成**。



虽然 Vue内部没有使用自定义元素，不过在应用实用自定义元素，或以自定义元素形式发布时，依然有很好的操作性。

Vue CLI也支持将Vue组件构建成为原生的自定义元素。