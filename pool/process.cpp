//
// Created by Administrator on 2021/2/2.
//

#include "process.h"
process::process()
{

}

process::process(int number)
{

}

process::process(int num, HookFunction* fun)
{

}

//进程销毁
void process::destroy_process()
{

}

//进程开始执行
void process::run()
{
    //创建子进程

}

void process::run(HookFunction  hook_Function, void* task_queue)
{

}

int process::getProcessNumber()
{
    return sysconf(_SC_NPROCESSORS_CONF);
}