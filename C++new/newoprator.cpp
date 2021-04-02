//
// Created by Administrator on 2021/3/11.
//
#include "newoprator.h"

/*
    内存动态分配与释放






 auto_ptr 成员方法
 get() 获取关联指针
 reset()  重置为空，delete其关联的指针
 release() 不delete关联指针，并返回关联指针。释放关联指针的所有权

 所有的智能指针类都有一个explicit构造函数，以指针作为参数，因此不能自动将指针转换为智能指针对象，必须显式调用：
    shared_ptr<double> pd;
    double *p_reg = new double;
    pd = p_reg;                               // not allowed (implicit conversion)
    pd = shared_ptr<double>(p_reg);           // allowed (explicit conversion)
    shared_ptr<double> pshared = p_reg;       // not allowed (implicit conversion)
    shared_ptr<double> pshared(p_reg);        // allowed (explicit conversion)

    对全部三种智能指针都应避免的一点：
    string vacation("I wandered lonely as a cloud.");
    shared_ptr<string> pvac(&vacation);   // No
    pvac过期时，程序将把delete运算符用于非堆内存，这是错误的。

    为什么摒弃 auto_ptr  ----避免潜在的内存崩溃问题。---- 所有权移交 再次使用



 智能指针   auto_ptr、unique_ptr和shared_ptr这几个智能指针背后的设计思想。我简单的总结下就是：将基本类型指针封装为类对象指针（这个类肯定是个模板，以适应不同基本类型的需求），并在析构函数里编写delete语句删除指针指向的内存空间。
    auto_ptr: （普通对象指针）转变为类对象指针 实现自动释放  不需要添加delete  在作用域介绍时  自动调用析构函数释放内存
        对于特定的对象，只能有一个智能指针可拥有，这样只有拥有对象的智能指针的构造函数会删除该对象。然后让赋值操作转让所有权
        const reference是智能指针作为参数传递的底线
        获取指向内存大小  成员函数  get()
        reset()  重新设置auto_ptr指向的对象。类似于赋值操作，但赋值操作不允许将一个普通指针指直接赋给auto_ptr，而reset()允许。 reset(0) 可以销毁对象释放内存
        release() 返回auto_ptr指向的那个对象的内存地址,并释放对这个对象的所有权。用此函数初始化auto_ptr时可以避免两个auto_ptr对象拥有同一个对象的情况（与get函数相比）

    unique_ptr:  类似于 Boost库提供的scoped_ptr
        对于特定的对象，只能有一个智能指针可拥有，这样只有拥有对象的智能指针的构造函数会删除该对象。然后让赋值操作转让所有权
        unique_ptr不能直接复制，必须使用std::move()转移其管理的指针，转移后原 unique_ptr 为空
        在编译时进行语法检查不允许一个对象由多个 unique_ptr占有。
            试图将一个 unique_ptr 赋值给另一个时，如果源 unique_ptr 是个临时右值，编译器允许这么做；
            如果源 unique_ptr 将存在一段时间，编译器将禁止这么做。

            unique_ptr<string> pu1(new string ("hello world"));
            unique_ptr<string> pu2;
            pu2 = pu1;                                      // #1 not allowed  报错   C++有一个标准库函数std::move()，让你能够将一个unique_ptr赋给另一个
            unique_ptr<string> pu3;
            pu3 = unique_ptr<string>(new string ("You"));   // #2 allowed  右值 无影响

    share_ptr:引用计数  具有引用成环的问题
        创建智能更高的指针，跟踪引用特定对象的智能指针数。这称为引用计数。例如，赋值时，计数将加1，而指针过期时，计数将减1,。当减为0时才调用delete
        如果程序要使用多个指向同一个对象的指针，应选择shared_ptr




 weak_ptr:， weak_ptr是为了配合shared_ptr而引入的一种智能指针，它更像是shared_ptr的一个助手而不是智能指针，因为它不具有普通指针的行为，没有重载operator*和->,它的最大作用在于协助shared_ptr工作，像旁观者那样观测资源的使用情况.
        其实weak_ptr本身设计的很简单，就是为了辅助shared_ptr的，它本身不能直接定义指向原始指针的对象，只能指向shared_ptr对象，同时也不能将weak_ptr对象直接赋值给shared_ptr类型的变量，最重要的一点是赋值给它不会增加引用计数


 make_unique

 */


/*  auto ptr C++98 提出  C++11 摒弃  */

/*
当异常退出时 或者直接返回时 delete 没有被执行  直接造成内存泄漏
 */
void  ptr_auto(std::string & str,int flag)
{
    std::string  *str_ptr =  new std::string(str);
    if(flag == 0)
        return;
    if(flag == 1)
        throw std::exception();
    delete str_ptr;
}


/*
 auto_ptr :将普通指针转变为 类对象指针  智能指针的思想 转化为类指针 通过自动条用析构函数实现内存管理

 */
void  ptr_auto1(std::string & str,int flag)
{
   std::auto_ptr<std::string> str_ptr(new std::string(str));
    if(flag == 0)
        return;
    if(flag == 1)
        throw std::exception();
    //delete str_ptr;
}



/*
    auto_ptr  运行时报错  所以摒弃 避免潜在的内存错误
    unique_ptr  编译时直接报错

 */

class test_struct{
public:
    test_struct(){
        data = 0;
        str = "";
        std::cout << "called construction function" << std::endl;}
    test_struct(int _data,std::string _str):data(_data),str(_str){
        std::cout << "called construction function" << std::endl;
    }
    ~test_struct(){
        std::cout << "called destruction function" << std::endl;
    }
    void setdata(int _data,std::string _str){
        data = _data;
        str = _str;
    }
    std::pair<int,std::string> getdata()
    {
        return std::pair<int,std::string>(data,str);
    }
private:
    int data;
    std::string str;
};

/*
 auto_ptr 成员函数
 auto_ptr 不要做为函数参数 避免函数内部改变所有权 引起程序崩溃  不能避免情况下  const reference是智能指针作为参数传递的底线。
 */
void auto_ptr_function()
{
    //get
    //ptr_int.get()  指向内存的地址
    int* ptr = new int(23);

    //动态内存初始化
    std::auto_ptr<int> ptr_int(ptr);
    std::auto_ptr<int> ptr_int13(new int(66));
    // 拷贝构造
    std::auto_ptr<int> ptr_int11(ptr_int);
    //m默认构造
    std::auto_ptr<int> ptr_int12;


    std::cout << ptr << std::endl << ptr_int.get() << std::endl;
    *ptr_int.get() = 200;
    std::cout << *ptr_int << std::endl;

    std::auto_ptr<test_struct> ptr_auto(new test_struct(0,"abcdefg"));
    std::cout << ptr_auto->getdata().first << '\t '<< ptr_auto->getdata().second<<std::endl;
    //reset  重新设置指向内存 会释放之前内存  只能统一类型对象重新指向
    ptr_auto.reset(new test_struct(100,"100"));
    std::cout << ptr_auto->getdata().first <<  "\t" << ptr_auto->getdata().second;
    //release 释放对象所有权 返回指针对象指向的内存地址  不会释放对象指向的内存
    std::auto_ptr<test_struct> ptr2(ptr_auto.release());
    if(ptr_auto.get() == nullptr)
        std::cout << "所有权被释放" <<std::endl;

    ptr2.reset(nullptr);
    std::cout << "reset(nullptr) 可以用于释放内存 " << std::endl;



}


int ptr_auto(){
    using namespace std;
    std::auto_ptr<std::string> films[5] =
            {
                    auto_ptr<string> (new string("Fowl Balls")),
                    auto_ptr<string> (new string("Duck Walks")),
                    auto_ptr<string> (new string("Chicken Runs")),
                    auto_ptr<string> (new string("Turkey Errors")),
                    auto_ptr<string> (new string("Goose Eggs"))
            };
    auto_ptr<string> pwin;
    pwin = films[2]; // films[2] loses ownership. 将所有权从films[2]转让给pwin，此时films[2]不再引用该字符串从而变成空指针
    cout << "The nominees for best avian baseballl film are\n";
    for(int i = 0; i < 5; ++i)
        cout << *films[i] << endl;  //报错 输出空指针
    cout << "The winner is " << *pwin << endl;
    return 0;
}

int ptr_unique(){
    using namespace std;
    std::unique_ptr<std::string> films[5] =
            {
                    unique_ptr<string> (new string("Fowl Balls")),
                    unique_ptr<string> (new string("Duck Walks")),
                    unique_ptr<string> (new string("Chicken Runs")),
                    unique_ptr<string> (new string("Turkey Errors")),
                    unique_ptr<string> (new string("Goose Eggs"))
            };
    unique_ptr<string> pwin;
    //pwin = films[2]; // 直接不能赋值  存在潜在内存错误  存在语法错误  优于 auto_ptr
    cout << "The nominees for best avian baseballl film are\n";
    for(int i = 0; i < 5; ++i)
        cout << *films[i] << endl;  //报错 输出空指针
    cout << "The winner is " << *pwin << endl;
    return 0;
}

/*返回  temp 为一个临时的右值*/
std::unique_ptr<test_struct> demo1()
{
    std::unique_ptr<test_struct> temp (new test_struct(1000,"1000"));
    return temp;
}

/*
 unique_ptr 成员函数的使用  唯一的  唯一所有权 编译时作为语法检查
 */
void ptr_unique_test()
{
    // get  release   reset 与auto_ptr  类似

    //动态内存初始化
    test_struct * ptr = new test_struct(1000,"1000");
    std::unique_ptr<test_struct> ptr_unique1(ptr);

    /*右值拷贝构造函数 --start*/
    std::unique_ptr<test_struct> ptr_unique2(new test_struct(1000,"1000"));
    std::unique_ptr<test_struct> ptr_unique3 = demo1();
    //移动语义初始化     使用move后，原来的指针仍转让所有权变成空指针，可以对其重新赋值
    std::unique_ptr<test_struct> ptr_unique4(move(ptr_unique3));
    /*右值拷贝构造函数 --end*/
    //c++ 14 特性 make_unique
    //std::unique_ptr<test_struct> ptr_unique2 = std::make_unique<test_struct>(1000,"1000");

    //std::move unique 指针转移  ptr_unique4 被置空
    std::unique_ptr<test_struct> ptr_unique5 = std::move(ptr_unique4);

    ptr_unique1.reset(nullptr);
    ptr_unique2.reset(nullptr);


    std::cout << "前面调用三次析构函数" << std::endl;

    std::unique_ptr<test_struct> p_ptr(new test_struct(100,"111"));
    p_ptr = nullptr; //置空直接释放内存
    std::cout << "前面调用1次析构函数" << std::endl;


    std::unique_ptr<test_struct> ptr_unique(new test_struct(100,"100"));
    std::unique_ptr<test_struct> ptr_unique11(new test_struct(200,"200"));

    std::cout << "ptr_unique 内存数据"  << ptr_unique->getdata().first << "\t" << ptr_unique->getdata().second << std::endl;
    std::cout << "ptr_unique11 内存数据"<< ptr_unique11->getdata().first << "\t" << ptr_unique11->getdata().second << std::endl;
    // swap 交换两个智能指针指向的对象
    ptr_unique.swap(ptr_unique11);
    std::cout << "ptr_unique 内存数据"  << ptr_unique->getdata().first << "\t" << ptr_unique->getdata().second << std::endl;
    std::cout << "ptr_unique11 内存数据"<< ptr_unique11->getdata().first << "\t" << ptr_unique11->getdata().second << std::endl;
    //也可以使用 标准的swap
    std::swap(ptr_unique,ptr_unique11);
    std::cout << "ptr_unique 内存数据"  << ptr_unique->getdata().first << "\t" << ptr_unique->getdata().second << std::endl;
    std::cout << "ptr_unique11 内存数据"<< ptr_unique11->getdata().first << "\t" << ptr_unique11->getdata().second << std::endl;
    ptr_unique = nullptr;
    ptr_unique11 = nullptr;

    // unique_ptr 转换为 shared_ptr     将unique_ptr 作为右值（临时对象转化）

    //unique_ptr 指向数组  test_struct[] 回调用delete[] 释放    或者自定义分配器释放
    std::unique_ptr<test_struct[]> parr(new test_struct[3]);
    parr = nullptr;
    //自定义分配释放器
    std::cout << "\n";
    auto self_delete = [](test_struct* test){delete[] test;};
    std::unique_ptr<test_struct,decltype(self_delete)> self_ptr(new test_struct[5],self_delete);
    self_ptr = nullptr;
    std::cout << "\n";

    auto test_ptr = new test_struct[3];
    std::unique_ptr<test_struct,decltype(self_delete)> self_ptr1(test_ptr,self_delete);
}


/*
 shared_ptr  存在计数问题  允许多个指向统一块内存
 */
int ptr_shared(){
    using namespace std;
    std::shared_ptr<std::string> films[5] =
            {
                    shared_ptr<string> (new string("Fowl Balls")),
                    shared_ptr<string> (new string("Duck Walks")),
                    shared_ptr<string> (new string("Chicken Runs")),
                    shared_ptr<string> (new string("Turkey Errors")),
                    shared_ptr<string> (new string("Goose Eggs"))
            };
    shared_ptr<string> pwin;
    pwin = films[2];
    cout << "The nominees for best avian baseballl film are\n";
    for(int i = 0; i < 5; ++i)
        cout << *films[i] << endl;  //报错 输出空指针
    cout << "The winner is " << *pwin << endl;
    return 0;
}

/*返回  temp 为一个临时的右值*/
std::unique_ptr<std::string> demo(const char * s)
{
    std::unique_ptr<std::string> temp (new std::string (s));
    return temp;
}


void demo_unique()
{
    std::string str = "adfadgafafg";
    std::unique_ptr<std::string> str_ptr = demo(str.c_str()); //返回值作为临时的右值 没有问题

    //C++有一个标准库函数std::move()，让你能够将一个unique_ptr赋给另一个,
    std::unique_ptr<std::string> str_ptr1 = std::move(str_ptr);
    if(str_ptr == nullptr)//使用move后，原来的指针仍转让所有权变成空指针，可以对其重新赋值。
    {
        str_ptr = demo("adfad");
        std::cout <<  *str_ptr << std::endl;
    }
    std::cout <<  *str_ptr1 << std::endl;

}


/*
 shared_ptr 循环引用问题
 */
class B;
class A{
public:
   A()  {std::cout <<"calling  class A construction function" << std::endl;}
   ~A() { std::cout <<"calling  class A destruction function" << std::endl;}
   void set_ptr(const std::shared_ptr<B> &ptr) {m_ptr_A = ptr;}
   void use_count(){std::cout << "b use count : " << m_ptr_A.use_count() << std::endl; }

private:
    std::shared_ptr<B>  m_ptr_A;
};


class B{
public:
    B()  {std::cout <<"calling  class B construction function" << std::endl;}
    ~B() { std::cout <<"calling  class B destruction function" << std::endl;}
    void set_ptr(const std::shared_ptr<A> &ptr) {m_ptr_B = ptr;}
    void use_count(){std::cout << "b use count : " << m_ptr_B.use_count() << std::endl; }
private:
    std::shared_ptr<A>  m_ptr_B;
};

/*
 shared_ptr  循环引用问题 成环造成内存泄漏

 */
void circulation_shared_ptr()
{
    using namespace  std;
    shared_ptr<A> ptr_A(new A());
    shared_ptr<B> ptr_B(new B());
    cout << "a use count : " << ptr_A.use_count() << endl; //获取所有者的数量
    cout << "b use count : " << ptr_B.use_count() << endl;

    //导致类对象不能被释放 内部应用计数始终为1
    ptr_A->set_ptr(ptr_B);
    ptr_B->set_ptr(ptr_A);

    cout << "a use count : " << ptr_A.use_count() << endl;
    cout << "b use count : " << ptr_B.use_count() << endl;
}




/*  shared_ptr  共享指针使用测试*/
/*
 new  与 make_shared 区别
 new 在构造是分配两次内存（技术控制块）
 make_shared：只会分配一次（一块大的内存，包含计数块 和 数据内存）
 make_shared make_unique  不能指定删除器。
 相比于直接使用new，make函数可以消除代码重复，提高异常安全，而且std::make_shared和std::allocate_shared生成的代码更小更快。
 不适合使用make函数的场合包括需要指定自定义删除器和想要传递大括号初始值。

 对于std::shared_ptr，使用make函数可能是不明智的场合包括（1）自定义内存管理函数的类、（2）内存紧张的系统中，有非常大的对象，然后std::weak_ptr比std::shared_ptr长寿。

 */
void test_shared_ptr()
{
    //get ()   swap()与上面一致
    //初始化
    test_struct * struct_ptr = new test_struct(100,"100");
    std::shared_ptr<test_struct> ptr(new test_struct);
    std::shared_ptr<test_struct> ptr1(struct_ptr);
    //std::make_shared
    std::shared_ptr<test_struct> ptr2 = std::make_shared<test_struct>(200,"200");
    ptr.reset();

    std::cout << "\n";
    //use_count  是获取该片内存有多个shared_ptr个对象正在引用。

    //unique：是否该智能指针独占某个指向的对象
    if(ptr1.unique())
        std::cout << "智能指针独占" << std::endl;
    //reset 与前面两个类似  多个引用时减1  独享时释放内存
    std::shared_ptr<test_struct> ptr3 = ptr1;
    std::shared_ptr<test_struct> ptr4 = ptr1;
    std::shared_ptr<test_struct> ptr5(ptr1);
    std::cout << ptr5.use_count() <<"\t" << ptr4.use_count() <<"\t" << ptr3.use_count() <<"\t" << ptr1.use_count() <<"\n";
    ptr1.reset();
    ptr2.reset();
    ptr3.reset();
    ptr4.reset();
    ptr5.reset();
    std::cout << ptr5.use_count() <<"\t" << ptr4.use_count() <<"\t" << ptr3.use_count() <<"\t" << ptr1.use_count() <<"\n";

    //自定义删除器
    FreeFunc<test_struct>        Object1;
    std::shared_ptr<test_struct>      sp1((test_struct*)malloc(sizeof(test_struct)), Object1);
    sp1.reset();
    std::cout << "\n";
    DeleteArrayFunc<test_struct> Object2;
    std::shared_ptr<test_struct>      sp2(new test_struct[4], Object2);
    sp2.reset();
    std::cout <<"\n";
    std::shared_ptr<test_struct[]>      sp3(new test_struct[3]);
    sp3 = nullptr;

    std::cout <<"\n";
    auto self_delete  = [](test_struct* struct_ptr){delete[] struct_ptr;};
    std::shared_ptr<test_struct>      sp4(new test_struct[2],std::default_delete<test_struct[]>());

    std::shared_ptr<test_struct>      sp5(new test_struct[2],self_delete);
    sp5.get()[1].setdata(100,"100");

    std::cout << sp5.get()[0].getdata().first  << "\t" <<sp5.get()[0].getdata().second <<std::endl;
    std::cout << sp5.get()[1].getdata().first  << "\t" <<sp5.get()[1].getdata().second <<  std::endl ;


}



class D;
class C{
public:
    C()  {std::cout <<"calling  class C construction function" << std::endl;}
    ~C() { std::cout <<"calling  class C destruction function" << std::endl;}
    void set_ptr(const std::shared_ptr<D> &ptr) {m_ptr_C = ptr;}
    void use_count(){std::cout << "a use count : " << m_ptr_C.use_count() << std::endl; }
private:
    std::shared_ptr<D>  m_ptr_C;
};


class D{
public:
    D()  {std::cout <<"calling  class D construction function" << std::endl;}
    ~D() { std::cout <<"calling  class D destruction function" << std::endl;}
    void set_ptr( std::shared_ptr<C>& ptr) {m_ptr_D = ptr;}
    void use_count(){std::cout << "b use count : " << m_ptr_D.use_count() << std::endl; }
private:
    std::weak_ptr<C>  m_ptr_D;
};



/*
 weak_ptr(弱指针)  解决环形问题 赋值给weak_ptr 不会增加计数
 */
void circulation_weak_ptr()
{
    using namespace  std;
    shared_ptr<C> ptr_C(new C());
    shared_ptr<D> ptr_D(new D());
    cout << "a use count : " << ptr_C.use_count() << endl; //获取所有者的数量
    cout << "b use count : " << ptr_D.use_count() << endl;

    ptr_C->set_ptr(ptr_D);
    ptr_D->set_ptr(ptr_C);

    cout << "a use count : " << ptr_C.use_count() << endl;
    cout << "b use count : " << ptr_D.use_count() << endl;
}


/*
 weak_ptr
 weak_ptr 比shared_ptr  后死
 */
void test_weak_ptr()
{
    using namespace std;
    shared_ptr<C> ptr_a(new C());     // 输出：calling  class C construction function
    shared_ptr<D> ptr_b(new D());     // 输出：calling  class D construction function

    cout << "ptr_a use count : " << ptr_a.use_count() << endl; // 输出：ptr_a use count : 1
    cout << "ptr_b use count : " << ptr_b.use_count() << endl; // 输出：ptr_b use count : 1

    weak_ptr<C> wk_ptr_a = ptr_a;
    weak_ptr<D> wk_ptr_b = ptr_b;

    //检查被引用的对象是否已删除
    if (!wk_ptr_a.expired())
    {
        //lock()  创建管理被引用的对象的shared_ptr (获取对应shared_ptr)
        wk_ptr_a.lock()->use_count();        // 输出：a use count : 0
    }

    if (!wk_ptr_b.expired())
    {
        wk_ptr_b.lock()->use_count();        // 输出：b use count : 0
    }

    // 编译错误
    // 编译必须作用于相同的指针类型之间
    // wk_ptr_a.swap(wk_ptr_b);         // 调用交换函数

    //释放被管理对象的所有权
    wk_ptr_b.reset();
    //检查被引用的对象是否已删除
    if (wk_ptr_b.expired())
    {
        cout << "wk_ptr_b is invalid" << endl;  // 输出：wk_ptr_b is invalid 说明改指针已经无效
    }

    wk_ptr_b = ptr_b;
    if (!wk_ptr_b.expired())
    {
        wk_ptr_b.lock()->use_count();        // 输出：this is class CB! 调用赋值操作后，wk_ptr_b恢复有效
    }

    // 编译错误
    // 编译必须作用于相同的指针类型之间
    // wk_ptr_b = wk_ptr_a;

    // 最后输出的引用计数还是1，说明之前使用weak_ptr类型赋值，不会影响引用计数
    cout << "ptr_a use count : " << ptr_a.use_count() << endl; // 输出：ptr_a use count : 1
    cout << "ptr_b use count : " << ptr_b.use_count() << endl; // 输出：ptr_b use count : 1
}







