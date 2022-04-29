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

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& ptr){
    _p=new T {*ptr.get()};  
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T> & ptr){
    delete _p;
    _p=new T{*ptr.get()};
}