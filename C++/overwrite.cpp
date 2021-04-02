//
// Created by Administrator on 2021/3/31.
//

#include "overwrite.h"
#include "../head.h"
/*

虚函数：
纯虚函数：

构造  移动赋值  移动构造
析构
异常
拷贝 深拷贝 浅拷贝
符号重写
友元类友元函数
内部类
常成员
静态成员
静态函数
引用
通过地址访问私有成员
函数重载
函数重写
函数覆盖
静态多态
动态多态
*/
/*
 C++ 面向对象   继承  封装  多态
 */

/*
 malloc  free
 new  delete
 new[]  delete[]
 */

/*
 static
 */

/*
 const
 */

/*
 define  与const  区别
 */

/*
 mutable
 */

/*
 explict
 */


/*第一*/
/*

 列表初始化
 构造
 复制构造函数
 赋值运算符
 移动构造
 移动赋值运算符
 析构
 const 成员
 static 成员
 const 成员函数
 static 成员函数
 非成员函数
 内部内
 explicit
 mutable

 */
class construct_fun{
public:
    construct_fun():c_number(0){

    };

    construct_fun(int _data,std::string _str,int len = 0):c_number(len) //列表方式初始化
    {

    }

    //拷贝构造  深拷贝 浅拷贝
    construct_fun(const construct_fun& AA):c_number(0)
    {

    }

    //赋值运算

    ~construct_fun()
    {
        if(point)
        {
            delete[] point;
            point = nullptr;
        }
    }

private:
    int  data;
    const int c_number;
    std::string str;
    int* point;
};



/*第二*/
/*
 虚函数
 纯虚函数
 继承多态
 静态多态
 动态多态
 */


/*第三*/