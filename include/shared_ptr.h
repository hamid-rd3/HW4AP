#ifndef SHARED_PTR
#define SHARED_PTR
#include <iostream>
template <typename T>
class SharedPtr {
public:
    SharedPtr();
    SharedPtr(T* ptr);
    ~SharedPtr();
    T* get(){return _p;}
private:
    T* _p;
};

#include <shared_ptr.hpp>

#endif // SHARED_PTR