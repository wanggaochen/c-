//
// 单例模式.
//

#ifndef SINGLETONTEMPLATE_H
#define SINGLETONTEMPLATE_H

#include "../head.h"

template <class T>
class SingleTemplate
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
    SingleTemplate()  = delete;
    SingleTemplate(SingleTemplate const&) = delete;

    ~SingleTemplate() = delete;

    SingleTemplate& operator=(SingleTemplate const&) = delete;
private:
    static T* pInst;
    static std::mutex* mutex_;
};

template <class T> T* SingleTemplate<T>::pInst = nullptr;
template <class T> std::mutex* SingleTemplate<T>::mutex_ = nullptr;

#endif //UNTITLED_SINGLETEMPLATE_H
