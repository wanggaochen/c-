//
// Created by Administrator on 2021/2/2.
//

#ifndef UNTITLED_PROCESS_H
#define UNTITLED_PROCESS_H
#include "../head.h"
typedef  void (HookFunction)(void* task_queue);

class process {
    //创建线程

    //进程销毁

    //进程开始执行

    //查看进程个数

    //查看进程状态

    //结束指定进程

    //进程设置执行函数

    //销毁线程
private:
    int process_num;
    HookFunction* _hookFunction;
    //执行函数 函数指针

};

class process_correspondence{

};
#endif //UNTITLED_PROCESS_H
