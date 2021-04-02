//
// Created by Administrator on 2021/3/31.
//

#ifndef UNTITLED_OVERWRITE_H
#define UNTITLED_OVERWRITE_H
#include <memory>

/*总结c++ 基础知识 写成CSDN 文章 */
class   base{
    //构造函数
    base()
    {
        data_base = nullptr;
        n_base = 0;

    }
    base(int n)
    {
        if(data_base)
        {
            delete[] data_base;
        }
     }
    //析构函数
private:
    int*    data_base;
    int     n_base;
};




#endif //UNTITLED_OVERWRITE_H
