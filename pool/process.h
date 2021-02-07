//
// Created by Administrator on 2021/2/2.
//

#ifndef UNTITLED_PROCESS_H
#define UNTITLED_PROCESS_H
#include "../head.h"
typedef  void (HookFunction)(void* task_queue);

class process {
    //创建线程
    process();

    process(int number);

    process(int num, HookFunction* fun);

    //进程销毁
    void destroy_process();

    //进程开始执行
    void run();

    void run(HookFunction  hook_Function, void* task_queue);

    //查看进程个数
    int getProcessNumber();


private:
    int process_num;
    //HookFunction* _hookFunction;
    //执行函数 函数指针

};

//进程通信
class process_correspondence{

};
#endif //UNTITLED_PROCESS_H
