## jQuery

它使用CSS选择器来访问和操作网页上的HTML元素（DOM对象）

jquery同时提供companion UI（用户界面）和插件。







## Prototype

**Prototype** 是一种库，提供用于执行常见 web 任务的简单 API。

**API** 是应用程序编程接口（Application Programming Interface）的缩写。它是包含属性和方法的库，用于操作 HTML DOM。

Prototype 通过提供类和继承，实现了对 JavaScript 的增强。

**提示：**Prototype 框架最大的部分就是对DOM的扩展。通过Prototype框架里的$()函数能够返回一个网页DOM元素，框架给这个元素添加了很多方便的方法。



## MooTools

**MooTools** 也是一个框架，提供了可使常见的 JavaScript 编程更为简单的 API。

MooTools 也含有一些轻量级的效果和动画函数。

**提示：**虽然Mootools跟Prototype几乎拥有一样的语法，但是它提供了比Prototype多的功能，而且更强大，拥有实用而清晰的文档和示例帮助你轻松入门。





您总是希望网页可以尽可能地快。您希望页面的容量尽可能地小，同时您希望浏览器尽可能多地进行缓存。

如果许多不同的网站使用相同的 JavaScript 框架，那么把框架库存放在一个通用的位置供每个网页分享就变得很有意义了。

CDN (Content Delivery Network) 解决了这个问题。CDN 是包含可分享代码库的服务器网络。

Google 为一系列 JavaScript 库提供了免费的 CDN，包括：

- jQuery
- Prototype
- MooTools
- Dojo
- Yahoo! YUI

但是由于 Google 在中国经常被GFW（防火长城，英文名称Great Firewall of China，简写为Great Firewall，缩写GFW）屏蔽，造成访问不稳定，所以建议使用百度静态资源公共库:[http://cdn.code.baidu.com/](https://cdn.code.baidu.com/)。

如需在您的网页中使用 JavaScript 框架库，只需在 <script> 标签中引用该库即可：

```html
<script src="http://apps.bdimg.com/libs/jquery/2.1.1/jquery.min.js"></script>
```

