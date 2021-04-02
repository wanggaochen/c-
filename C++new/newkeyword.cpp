//
// Created by Administrator on 2021/3/31.
//
#include "newkeywad.h"

class my_date
{
public:
    my_date(int _data,std::string _str,my_date* _next = nullptr):data(_data),str(_str),next(next){
        std::cout << " 调用构造函数" <<std::endl;
    }
    my_date()
    {

    }

    my_date(const my_date & _data)
    {
        data = _data.data;
        str = _data.str;
        next = nullptr;
        std::cout << " 拷贝构造" <<std::endl;
    }
    my_date* next;
    friend std::ostream  &operator<<(std::ostream &cout,const my_date _my_data);
    std::pair<int,std::string> getdata()
    {
        return  std::pair<int,std::string>(data,str);
    }
    void setdata(int _data,std::string _str){
        data = _data;
        str = _str;
    }
    ~my_date()
    {
        std::cout << " 调用析构函数" <<std::endl;
    }
private:
    int data;
    std::string str;
};

std::ostream & operator<<(std::ostream &cout, my_date _my_data)
{
    cout<<_my_data.data << "\t" <<_my_data.str << "\n";
    return cout;
}

/*
C++11关键字: 新增 或者改变原有含义：
 char16_t:
 char32_t:
 constexpr:
 noexcept:
 static_assert;
 alignas:
 alignof:
 nullptr:
 decltype:
 auto:
 register:
 struct:
 using:
 sizeof;
 extern:
 export:
 delete:
 default:
 class:
*/

/*
 nullptr： 用来区分空指针 与零
 nullptr代替UNLL传统 C++ 会把 NULL、0 视为同一种东西，这取决于编译器如何定义 NULL，有些编译器会将 NULL 定义为 ((void*)0)，有些则会直接将其定义为 0
C++11 引入了 nullptr 关键字，专门用来区分空指针、0
当需要使用 NULL 时候，养成直接使用 nullptr的习惯。

 */



/*
 auto：
 C++11 引入了 auto 和 decltype 这两个关键字实现了类型推导，让编译器来推导变量的类型。
 c++11之前作为自动变量 ，atuo(自动获取变量类型)
 自动变量：
 局部变量，如不作专门说明为静态变量，都是动态分配存储空间，存储在动态存储区中。这种变量叫自动变量。这种变量只在定义它们的时候才创建，在定义它们的函数返回时系统回收变量所占存储空间。
 对这些变量存储空间的分配和回收是由系统自动完成的，所以也叫自动变量。一般情况下，不作专门说明的局部变量，均是自动变量。
 auto 在很早以前就已经进入了 C++，但是他始终作为一个存储类型的指示符存在，与 register 并存。
 在传统 C++ 中，如果一个变量没有声明为 register 变量，将自动被视为一个 auto 变量。而随着 register作用（之前代表寄存区变量 多次调用放入寄存器 加速访问速度）被弃用，
 对 auto 的语义变更也就非常自然了
auto 变量必须初始化
auto 不能用于函数传参
auto 不能用于推导数组类型
 */
/* auto 类型推导   */
void keyword_auto()
{

    using  namespace  std;
    map<int,my_date> map_data;
    my_date _my_data(1,"chen");
    map_data[1] = _my_data;
    _my_data.setdata(2,"bo");
    map_data[2] = _my_data;
    _my_data.setdata(3,"en");
    map_data[3] = _my_data;
    for(auto it:map_data)
    {
        std::cout << it.first << "\t" << it.second << std::endl;
    }
}

/*
 亡值
    C++11中的将亡值是随着右值引用的引入而新引入的。换言之，“将亡值”概念的产生，是由右值引用的产生而引起的，将亡值与右值引用息息相关
        1）返回右值引用的函数的调用表达式
        2）转换为右值引用的转换函数的调用表达
 在C++11中，用左值去初始化一个对象或为一个已有对象赋值时，会调用拷贝构造函数或拷贝赋值运算符来拷贝资源，而当用一个右值（包括纯右值和将亡值）来初始化或赋值时，
 会调用移动构造函数或移动赋值运算符来移动资源，从而避免拷贝，提高效率。当该右值完成初始化或赋值的任务时，它的资源已经移动给了被初始化者或被赋值者，
 同时该右值也将会马上被销毁（析构）。也就是说，当一个右值准备完成初始化或赋值任务时，它已经“将亡”了。这种右值常用来完成移动构造或移动赋值的特殊任务，
 扮演着“将亡”的角色，所以C++11给这类右值起了一个新的名字——将亡值。

    返回类型为对象的右值引用的函数调用或重载运算符表达式，例如 std::move(x)；
    转换为对象的右值引用类型的转型表达式，例如 static_cast<char&&>(x)；
 */

my_date fun_AA()
{
    return my_date(8,"8");
}

void  dead_value()
{
    my_date data(100,"100");
    my_date data1  = data; //调用拷贝构造函数拷贝资源

    my_date data2 = std::move(data1);
    my_date data3 = static_cast<my_date&&>(data);

    my_date data4  = fun_AA();
    data2.setdata(1,"a");
    data3.setdata(2,"b");
    std::cout << data << std::endl;
    std::cout << data1 << std::endl;
}






/*
  register  c++ 11 之前寄存器变量 在程序中 多次调用变量放入寄存器 加速访问速度
  c++11 弃用
 */

/*
 decltype
auto decltype 都是在编译时 推导变量类型
decltype： 类型说明符
    decltype ( 实体 )	(1)	(C++11 起)
    decltype ( 表达式 )	(2)	(C++11 起)


 若实参为无括号的标识表达式或无括号的类成员访问表达式，则 decltype 产生以此表达式命名的实体的类型
 若 表达式 的值类别为左值，则 decltype 产生 T&  注意如果对象的名字带有括号，则它被当做通常的左值表达式
 若 表达式 的值类别为纯右值，则 decltype 产生 T

 若 表达式 的值类别为亡值，则 decltype 产生 T&&；


 注意如果对象的名字带有括号，则它被当做通常的左值表达式，从而 decltype(x) 和 decltype((x)) 通常是不同的类型。在难以或不可能以标准写法进行声明的类型时，decltype 很有用
 在c++17 中添加了更多特性



 decltype  + 变量
 decltype  + 表达式
 decltype  + 函数

*/

int fun()
{
    return 0;
}

int fun(int)
{
    return 0;
}



void keyword_decltype()
{
    //变量
    const  int n_data = 10;
    decltype(n_data) b = 10.0 ;//const int
    decltype(n_data) a = 20;  //const int
    decltype((n_data)) c = a ;  //const int&

    int data1 = 30;
    decltype(data1) aa = 20;
    decltype((data1)) bb = aa;  //int&
    bb = 100;
    std::cout << aa << "\t"  << bb << std::endl;



    //表达式


    //函数

}
