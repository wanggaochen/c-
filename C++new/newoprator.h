//
// Created by Administrator on 2021/3/11.
//

#ifndef UNTITLED_NEWOPRATOR_H
#define UNTITLED_NEWOPRATOR_H
#include <iostream>
#include <memory>
#include <exception>

#include<utility>

#endif //UNTITLED_NEWOPRATOR_H
int ptr_auto();
int ptr_shared();
int ptr_unique();
void ptr_unique_test();

void demo_unique();
void circulation_shared_ptr();
void circulation_weak_ptr();
void test_weak_ptr();

void  ptr_auto1(std::string & str,int flag);
void  ptr_auto(std::string & str,int flag);
void auto_ptr_function();
void test_shared_ptr();
//用来释放malloc出来的函数对象
template<class T>
class FreeFunc{
public:
    void operator()(T* ptr)
    {
        std::cout << "free:" << ptr << std::endl;
        free(ptr);
    }
};

//用来释放new[]出来的函数对象
template<class T>
class DeleteArrayFunc {
public:
    void operator()(T* ptr)
    {
        std::cout << "delete[]" << ptr << std::endl;
        delete[] ptr;
    }
};

//用来释放文件描述符的函数对象
template<class T>
class ClosefdFunc{
public:
    void operator()(T* fd)
    {
        std::cout << "close fd" << fd << std::endl;
        fclose(fd);
    }
};
