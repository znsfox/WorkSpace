每个Vue应用都是用`Vue`函数都是通过创建一个Vue实例开始的，

虽然没有完成遵循MVVM模型，但是Vue的设计也受到了它的启发，因此在文档中经常会使用VM(view-modle)来表示Vue实例。

**当创建一个Vue实例时，你可以传入一个选项对象**。这些教程主要描述的就是如何使用这些选项来创建你想要的行为。

一个Vue应用由一个**通过new Vue创建的根实例**、以及可选的嵌套的、可复用的组件树组成。

举个例子，一个todo应用的组件树可以是这样的：

```
根实例
└─ TodoList
   ├─ TodoItem
   │  ├─ TodoButtonDelete
   │  └─ TodoButtonEdit
   └─ TodoListFooter
      ├─ TodosButtonClear
      └─ TodoListStatistics
```

**所有组件都是Vue实例，并且接受相同的选项对象。一些根实例特有的选项除外。**



当一个Vue实例被创建时，它将data对象中的所有property加入到Vue的响应式系统中。

当这些 property 的值发生改变时，视图将会产生“响应”，即匹配更新为新的值。

```js
// 我们的数据对象
var data = { a: 1 }

// 该对象被加入到一个 Vue 实例中
var vm = new Vue({
  data: data
})

// 获得这个实例上的 property
// 返回源数据中对应的字段
vm.a == data.a // => true

// 设置 property 也会影响到原始数据
vm.a = 2
data.a // => 2

// ……反之亦然
data.a = 3
vm.a // => 3
```



当这些数据改变时，视图会进行重渲染。值得注意是，只有当实例被创建时就已经存在于`data`中的property才是响应式的，也就是说，如果你添加一个新的propetry,比如：

```
vm.b = 'hi'
```

那么对 `b` 的改动将不会触发任何视图的更新。如果你知道你会在晚些时候需要一个 property，但是一开始它为空或不存在，那么你仅需要设置一些初始值。比如：

```
data: {
  newTodoText: '',
  visitCount: 0,
  hideCompletedTodos: false,
  todos: [],
  error: null
}
```

这里唯一的例外是使用 `Object.freeze()`，这会阻止修改现有的 property，也意味着响应系统无法再*追踪*变化。

```
var obj = {
  foo: 'bar'
}

Object.freeze(obj)

new Vue({
  el: '#app',
  data: obj
})
<div id="app">
  <p>{{ foo }}</p>
  <!-- 这里的 `foo` 不会更新！ -->
  <button v-on:click="foo = 'baz'">Change it</button>
</div>
```





除了数据 Propetry,Vue还暴露了一些有用的实例与方法，它们都有前缀`$`,以便和用户自定义的property分开。



实现生命周期钩子：

每个Vue实例在被创建时都要经历一系列的初始化过程。例如，需要设置数据监听、编译模板、将实例挂载到DOM,并在数据变化时更新DOM，同时在这个阶段也会运行一些如`生命周期钩子`的函数，**这给了用户在不同阶段添加自己代码的机会。**



比如`created`可以在一个实例被创建后执行代码：

```
new Vue({
  data: {
    a: 1
  },
  created: function () {
    // `this` 指向 vm 实例
    console.log('a is: ' + this.a)
  }
})
// => "a is: 1"
```

也有一些其它的钩子，在实例生命周期的不同阶段被调用，如 [`mounted`](https://cn.vuejs.org/v2/api/#mounted)、[`updated`](https://cn.vuejs.org/v2/api/#updated) 和 [`destroyed`](https://cn.vuejs.org/v2/api/#destroyed)。生命周期钩子的 `this` 上下文指向调用它的 Vue 实例。

### 生命周期图示

下图展示了实例的生命周期。你不需要立马弄明白所有的东西，不过随着你的不断学习和使用，它的参考价值会越来越高。

<img src="https://cn.vuejs.org/images/lifecycle.png" alt="Vue 实例生命周期" style="zoom:67%;" />