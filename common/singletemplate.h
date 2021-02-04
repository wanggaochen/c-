//
// Created by Administrator on 2021/2/4.
//

#ifndef SINGLETONTEMPLATE_H
#define SINGLETONTEMPLATE_H

#include <cstdlib> // for NULL
#include <mutex>

template <class T>
class SingletonTemplate
{
public:
    static T* Instance() {
        if(!pInst) {
            if (!mutex_) {
                mutex_ = new std::mutex();
            }
            mutex_->lock();
            if(!pInst) {
                pInst = new T;
            }
            mutex_->unlock();
        }

        return pInst;
    }

public:
    SingletonTemplate()  = delete;
    SingletonTemplate(SingletonTemplate const&) = delete;

    ~SingletonTemplate() = delete;

    SingletonTemplate& operator=(SingletonTemplate const&) = delete;
private:
    static T* pInst;
    static std::mutex* mutex_;
};

template <class T> T* SingletonTemplate<T>::pInst = nullptr;
template <class T> std::mutex* SingletonTemplate<T>::mutex_ = nullptr;

#endif //UNTITLED_SINGLETEMPLATE_H
