# 学习笔记

### 基本概念
1. 并查集是一种数据结构
2. 并查集这三个字，一个字代表一个意思。
3. 并（Union），代表合并
4. 查（Find），代表查找
5. 集（Set），代表这是一个以字典为基础的数据结构，它的基本功能是合并集合中的元素，查找集合中的元素
6. 并查集的典型应用是有关连通分量的问题
7. 并查集解决单个问题（添加，合并，查找）的时间复杂度都是O(1)O(1)
8. 因此，并查集可以应用到在线算法中

### 并查集的实现 
* 数据结构
+ 并查集跟树有些类似，只不过她跟树是相反的。在树这个数据结构里面，每个节点
  会记录它的子节点。在并查集里，每个节点会记录它的父节点。
  
~~~ c++
class  UnionFind {
private:
	unordered_map<int, int> father;
}
~~~

* 初始化
+ 当把一个新节点添加到并查集中，它的父节点应该为空

~~~ c++
void add(int x) {
	if (!father.count(x)) {
		father[x] = -1;
	}
}
~~~

* 合并两个结点
+ 如果发现两个节点是连通的，那么就要把他们合并，也就是他们祖先是相同的。这里究竟把
  谁当成父节点一般是没有问题的
  
~~~
void merge(int x, int y) {
	int root_x = find(x);
	int root_y = find(y);
	
	if (root_x != root_y) {
		father[root_x] = root_y;
	}
}
~~~
  
* 两节点是否连通
+ 我们判断两个节点是否处于同一个连通分量的时候，就需要判断它们的祖先是否相同
+ 这里有一个优化的点： 如查我们的树很深，比如退化成链表，那么每次查询的效率都 
  会非常低。所以我们要做一下路径压缩，也就树的高度固定为二
~~~
bool is_connected(int x, int y) {
	return find(x) == find(y);
}
~~~


* 查找祖先 
+ 查找祖先的方法是：如果节点的父节点不为空，那就不断迭代。

~~~
int find(int x) {
	int root = x;
	while(father[root] != -1) {
		root = father[root];
	}
	return root;
~~~

* 路径压缩	
+ 	这里有一个优化的点：如果我们树很深，比如说退化成链表，那么每次查询的效率都会
	非常低。所以我们要做一下路径压缩。也就是把树的深度固定为二。这么做可行的原因
	是，并查集只是记录了节点之间的连通关系，而节点相互连通只需要有一个相同的祖先
	就可以了。路径压缩可以用递归，也可以迭代。这里用迭代的方法。

~~~	
int find(int x) {
	int root = x;
	
	while (father[root] != -1) {
		root = father[root];
	}
	// 路径压缩
	while (x != root) {
		int original_father = father[x];
		father[x] = root;
		x = original_father;
	}
}
~~~








