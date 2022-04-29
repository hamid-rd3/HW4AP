template <typename T>
SharedPtr<T>::SharedPtr(T* ptr)
    : _p { ptr }
    
{
    cnt++;
}

template <typename T>
SharedPtr<T>::SharedPtr()
{
    _p = nullptr;
}

template <typename T>
T* make_shared(T t)
{
    return new T { t };
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{   cnt=cnt-=1;
    delete _p;
    _p = nullptr;
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& ptr)
{
    cnt+=(++ptr.cnt);
    _p = new T { *ptr.get() };
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>& ptr)
{
    delete _p;
    _p = new T { *ptr.get() };
}

template <typename T>
const size_t SharedPtr<T>::use_count()const{
    return cnt;
}