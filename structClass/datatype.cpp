//
// Created by Administrator on 2021/2/7.
//

#include "datatype.h"

/*
 枚举  c++11 新增枚举类
*/

/*
 结构体  位结构
 */


/*
链表
*/


bool cmp(const int & a, const int & b)
{
    return a>b?true: false;
}

bool cmp1(const int & a, const int & b)
{
    return a<b?true: false;
}


void init_forward_list()
{
    //
    std::forward_list<int> list_pre;
    std::forward_list<int> list_pre1 {1,2,3,4};  //  std::forward_list<int> list_pre1 = {1,2,3,4};
    std::forward_list<int> list_pre2(list_pre1);
    std::forward_list<int> list_pre3(10);
    std::forward_list<int> list_pre4(10,10);
    list_pre1.push_front(100);
    /*print_list(list_pre1);
    list_pre1.pop_front();
    print_list(list_pre1);*/
    //std::cout << list_pre1.front();
    list_pre1.insert_after(list_pre1.cbegin(),10);
    list_pre1.insert_after(list_pre1.cbegin(),1);
    list_pre1.insert_after(list_pre1.cbegin(),10);
    list_pre1.insert_after(list_pre1.cbegin(),10);
    list_pre1.insert_after(list_pre1.cbegin(),10);
    list_pre1.insert_after(list_pre1.cbegin(),10);

    //print_list(list_pre1);

    list_pre1.sort(cmp);



    list_pre1.unique();
    std::cout << '\n';
    print_list(list_pre1);

    //list_pre1.reverse();
    std::cout << '\n';
    list_pre1.sort(cmp1);
    print_list(list_pre1);
    std::cout << '\n';
    list_pre1.emplace_after(list_pre1.begin(),10);
    print_list(list_pre1);
    std::forward_list<int>::iterator  it = list_pre1.before_begin();


}

void use_list()
{
    std::list<int> list{1,5,6,9,1,5,6,9};

}


/*
 队列
 */


/*
 栈
 */


/*
 树 二叉树  平衡 排序
 */


/*
 vector  std::array
 */

/*
 map  hash_map  set_map
 */

