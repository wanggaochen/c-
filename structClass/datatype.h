//
// Created by Administrator on 2021/2/7.
//  容器库   基本数据结构
//
//

#ifndef UNTITLED_DATATYPE_H
#define UNTITLED_DATATYPE_H
#include <forward_list>
#include <queue>
/*
 * c++ 内部结构的理解与应用
 * list  vector  tree  stack   bit queue 图  可变数组
 * */

/*
 枚举  c++11 新增枚举类
*/

/*
 结构体  位结构
 */


#include <list>
#include <iostream>

/*
链表 单向链表 双向链表  循环链表  利用零碎的空间
 单向链表：
    只有后驱指针
 双向链表：
    有前后驱指针   从双向链表的任意位置开始，都能访问所有的节点。

 环链表： 双指针，即通过使用一快一慢不同速度的两个指针来遍历链表，如果有环，快的总会与慢的相遇。

 std::list 为双向链表
        提供函



 std::std::forward_list  单向量表 更节省空间
        构造
        赋值 assign
        清除
        插入删除
        排序  默认从小到大   bool cmp(const type& a, const type& b);设置排序方式
        合并
        正反向迭代器
        是否为空
        去重  去除连续的重复元素 达不到全部去重效果
        翻转
        元素后原位构造
*/

template <class T>
struct list_node {
    T data;
    list_node* next;
    list_node(list_node<T>* ptr = nullptr )
    {
        next = nullptr;
    }

    list_node(const T &item,list_node<T>* ptr = nullptr)
    {
        data = item;
        next = ptr;
    }
};
template <class T>
class single_list
{
public:
    //无参数的构造函数
    single_list(){head = new list_node<T>;}

    //带参数的构造函数
    single_list(const T &item){head = new list_node<T>(item);}

    //拷贝构造函数
    single_list(single_list<T> &List);

    //析构函数
    ~single_list(){Clear();}

    //重载函数:赋值
    single_list<T>& operator=(single_list<T> &List);

    //链表清空
    void Clear();

    //获取链表长度
    int Length() const;

    //获取链表头结点
    list_node<T>* GetHead() const;

    //设置链表头结点
    void SetHead(list_node<T> *p);

    //查找数据的位置，返回第一个找到的满足该数值的结点指针
    list_node<T>* Find(T &item);

    //定位指定的位置，返回该位置上的结点指针
    list_node<T>* Locate(int pos);

    //在指定位置pos插入值为item的结点，失败返回false
    bool Insert(T &item, int pos);

    //删除指定位置pos上的结点，item就是该结点的值，失败返回false
    bool Remove(int pos, T &item);

    //获取指定位置pos的结点的值，失败返回false
    bool GetData(int pos, T &item);

    //设置指定位置pos的结点的值，失败返回false
    bool SetData(int pos, T &item);

    //判断链表是否为空
    bool IsEmpty() const;

    //打印链表
    void Print() const;

    //链表排序
    void Sort();

    //链表逆置
    void Reverse();
private:
    list_node<T>* head;
};


template <class T>
void print_list(const std::forward_list<T> &list)
{
    for(auto data :list)
    {
        std::cout << data << std::endl;
    }
}

/*链表的使用*/
void init_forward_list();

void use_list();



/*
 队列 线性结构先进先出 队尾添加元素，在队头删除元素   基于数组的队列  基于链表的队列 非常简单的数据结构
 */


/*
 栈      先进后出的线性结构 只能在栈顶进行插入删除等操作
         进栈
         出栈
         栈大小
         访问栈顶元素
         是否为空栈
 */


/*
 树 二叉树  平衡 排序
 */


/*
 vector  std::array

 vector:顺序容器 动态数组
 */



/*
 map  hash_map  set_map
 */





#endif //UNTITLED_DATATYPE_H
