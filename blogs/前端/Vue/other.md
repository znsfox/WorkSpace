## attribute：

### vm.$attrs:

contails parent-scope attribute buildings(except  for class or style) that are not recognized(and extracted) as component props or components,when a components doesn't have any declared props or customed events,and can be passed down to an inner component via `v-bind="$attrs"` - useful when creating higher-order components.





### listeners：

包含了父作用域中的 (不含 .native 修饰器的) v-on 事件监听器。它可以通过 v-on=”$listeners” 传入内部组件——在创建更高层次的组件时非常有用。





### key:

虚拟DOM的作用：

```
虚拟DOM就是为了解决浏览器性能问题而被设计出来的。如前，若一次操作中有10次更新DOM的动作，虚拟DOM不会立即操作DOM，而是将这10次更新的diff内容保存到本地一个JS对象中，最终将这个JS对象一次性attch到DOM树上，再进行后续操作，避免大量无谓的计算量，所以，用JS对象模拟DOM节点的好处是，页面的更新可以先全部反映在JS对象(虚拟DOM)上，操作内存中的JS对象的速度显然要更快，等更新完成后，再将最终的JS对象映射成真实的DOM，交由浏览器去绘制。
```

The special attribute of `key` is mainly used in virtual DOM algorithm, it can identify old or new nodes when comparing VNodes.

when using key, it will rearrange the order of the elements based on the `key`'s changes

The most usage of `key` is to combine v-for:

<ul>  <li v-for="item in items" :key="item.id">...</li> </ul>

## Vue路由：

Vue Router 是 [Vue.js](http://cn.vuejs.org/) 官方的路由管理器。它和 Vue.js 的核心深度集成，让构建单页面应用变得易如反掌。路由实际上就是可以理解为指向，就是我在页面上点击一个按钮需要跳转到对应的页面，这就是路由跳转；



## component:

### prop:

prop是组件上的自定义的attribute。when a value is passed to a prop attribute,it becomes a property of that property.





## abbreviation:

`:` 是指令 `v-bind`的缩写，`@`是指令`v-on`的缩写；`.`是修饰符





## instance Methods/Lifecycle

### mount

If a Vue instance didn’t receive the `el` option at instantiation, it will be in “unmounted” state, without an associated DOM element. `vm.$mount()` can be used to manually start the mounting of an unmounted Vue instance.

If `elementOrSelector` argument is not provided, the template will be rendered as an off-document element, and you will have to use native DOM API to insert it into the document yourself.

The method returns the instance itself so you can chain other instance methods after it.



## .sync 修饰符

在有些情况下，我们可能需要对一个 prop 进行“双向绑定”。不幸的是，真正的双向绑定会带来维护上的问题，因为子组件可以变更父组件，且在父组件和子组件都没有明显的变更来源。

这也是为什么我们推荐以 `update:myPropName` 的模式触发事件取而代之。举个例子，在一个包含 `title` prop 的假设的组件中，我们可以用以下方法表达对其赋新值的意图：

```
this.$emit('update:title', newTitle)
```

然后父组件可以监听那个事件并根据需要更新一个本地的数据 property。例如：

```
<text-document
  v-bind:title="doc.title"
  v-on:update:title="doc.title = $event"
></text-document>
```

为了方便起见，我们为这种模式提供一个缩写，即 `.sync` 修饰符：

```
<text-document v-bind:title.sync="doc.title"></text-document>
```



## instance Methods/Event

### emit

Trigger an event on the current instance. Any additional arguments will be passed into the listener’s callback function.





npm i css-loader -D

npm install vue-loader vue-template-compiler -D

npm i -D file-loader url-loader

npm i style-loader -D

npm i stylus stylus-loader -D

npm install html-webpack-plugin -D

npm install clean-webpack-plugin -D





yarn add -D eslint eslint-plugin-vue