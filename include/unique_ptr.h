#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template <typename T>
class UniquePtr {
public:
    UniquePtr(T* p);
    UniquePtr();
    ~UniquePtr();
    UniquePtr(const UniquePtr& ptr);
    // friend T* make_unique(T t) {  return new T { t };}
private:
    T* _p;
};




#include <unique_ptr.hpp>

#endif // UNIQUE_PTR