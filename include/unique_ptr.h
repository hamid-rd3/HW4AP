#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#include <iostream>
template <typename T>
class UniquePtr {
public:
    UniquePtr(T* p);
    UniquePtr();
    ~UniquePtr();
    UniquePtr(const UniquePtr& ptr);
    T* get()const{return _p;};
    T operator*()const;
    UniquePtr& operator=(const UniquePtr& ptr);
    // friend T* make_unique(T t) {  return new T { t };}
private:
    T* _p;
};




#include <unique_ptr.hpp>

#endif // UNIQUE_PTR