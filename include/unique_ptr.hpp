template <typename T>
UniquePtr<T>::UniquePtr(T* p)
    : _p { p }
{
}
template <typename T>
UniquePtr<T>::UniquePtr(){
    _p=nullptr;
}
template<typename T>
UniquePtr<T>::~UniquePtr(){
    delete _p;
    _p=nullptr;
}

template <typename T>
T* make_unique(T t) {  return new T { t };}

template <typename T>
UniquePtr<T>::UniquePtr(const UniquePtr& ptr){
    
}


