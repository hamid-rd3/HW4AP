template <typename T>
SharedPtr<T>::SharedPtr(T* ptr)
    : _p { ptr }
{
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
SharedPtr<T>::~SharedPtr(){
    delete _p;
    _p=nullptr;
}