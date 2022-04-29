#ifndef SHARED_PTR
#define SHARED_PTR
#include <iostream>
template <typename T>
class SharedPtr {
public:
    SharedPtr();
    SharedPtr(T* ptr);
    ~SharedPtr();
    SharedPtr(SharedPtr<T>& ptr);
    T* get()const{return _p;}
    SharedPtr<T>& operator=(SharedPtr<T>& ptr);
    const size_t& use_count()const;
    T operator*()const{return *_p;}
    T* operator->()const{return _p;};
private:
    T* _p;
    size_t* cnt;
};

#include <shared_ptr.hpp>

#endif // SHARED_PTR