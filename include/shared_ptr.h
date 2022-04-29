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
    T* get(){return _p;}
    SharedPtr<T>& operator=(SharedPtr<T>& ptr);
private:
    T* _p;
};

#include <shared_ptr.hpp>

#endif // SHARED_PTR