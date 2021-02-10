java中的"..."是什么？

可变长参数，就是这个位置可以传入任意个该类型参数，简单来说就是个数组



## java集合概览：

### List:

ArrayList: 数组

Vector: 数组

LinkedList: 双向链表

List:

List:





# [ArrayDeque类的使用详解](https://www.cnblogs.com/chenglc/p/10722304.html)

`ArrayDeque`是`Deque`接口的一个实现，使用了可变数组，所以没有容量上的限制。

同时，`ArrayDeque`是线程不安全的，在没有外部同步的情况下，不能再多线程环境下使用。

`ArrayDeque`是`Deque`的实现类，可以作为栈来使用，效率高于`Stack`；

也可以作为队列来使用，效率高于`LinkedList`。

需要注意的是，`ArrayDeque`不支持`null`值。