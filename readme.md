
```plaintext
[ 内存池 ] 
  |
可deallocate 如果能正好拼接上


[
  [===========]
  [===========]
]
交叉释放

链表型内存池


[ 容器 ]
  |
[ 其它特定的数据容器 ],例如tree,linklist

[ 函数算法 ]

[ 管道组合 ]

一个可管道的算法

接收一个容器和其它参数
1. 要么产生一个新的容器
2. 要么修改输入的容器

算法的过程中所有的容器大小都是固定的

使用迭代器来连接容器

先确定要实现的算法,为了减少记忆的代码量,已有的算法不实现


如:
std::count
std::count_if
std::accumulate
std::unique()
等

要实现的算法
map 组合
reduce
take
drop
filter
join
split
counted
key
value

最简单的就是创建新的容器


make_cr

```

目的

设计一个库,给OI选手用,

- c++14标准,因为noilinux2.0 默认支持
- 简单,易用!!!,源代码容易记忆!!!
- 大量的例子
- 函数式编程风格
