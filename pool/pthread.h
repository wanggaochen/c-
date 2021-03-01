//
// Created by Administrator on 2021/2/2.
//

#ifndef UNTITLED_PTHREAD_H
#define UNTITLED_PTHREAD_H
#include <queue>
#include <functional>
#include <future>

class pthread {
    pthread();
    pthread(unsigned  count);
    ~pthread();
    void run();
    void wait();
    void destroy();
private:
    unsigned thread_count;
    using TaskTy = std::function<void()>;
    using PackagedTaskTy = std::packaged_task<void()>;
    std::mutex queue_lock;
    std::condition_variable queue_condition;
};

class pthread_correspondence{

};

#endif //UNTITLED_PTHREAD_H
