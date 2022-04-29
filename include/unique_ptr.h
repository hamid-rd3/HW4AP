#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#include <iostream>
template <typename T>
class UniquePtr {
public:
    UniquePtr(T* p);
    UniquePtr();
    ~UniquePtr();
    UniquePtr(const UniquePtr<T>& ptr);
    T* get()const{return _p;};
    T operator*()const{return *_p;};
    T* operator-> ()const{return _p;};
    UniquePtr<T>& operator=(const UniquePtr<T>& ptr);
    void reset(){this->~UniquePtr();}
    void reset(T* ptr );
    operator bool()const;
    T* release();
    // friend bool operator()();
    // friend T* make_unique(T t) ;
private:
    T* _p;
};
#include <unique_ptr.hpp>

#endif // UNIQUE_PTR