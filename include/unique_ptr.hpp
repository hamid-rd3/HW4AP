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
UniquePtr<T>::UniquePtr(const UniquePtr& ptr){
    throw std::logic_error ("cant copy uniqueptr !");
}
template <typename T>
UniquePtr<T>& UniquePtr<T>::operator=(const UniquePtr<T>& ptr){
    throw std::logic_error ("cant copy uniqueptr !");
}

template<typename T>
void UniquePtr<T>::reset(T* ptr){
    delete _p;
    _p=ptr;    
}

template <typename T>
T* make_unique(T t) {  return new T { t };}

// template <typename T>
// bool operator()(const UniquePtr<T>& ptr) {
//     if(ptr.get()==nullptr)
//         return false;
//     else {
//         return true;
//     }
// }
template <typename T>
UniquePtr<T>::operator bool()const{
    return (_p==nullptr)? false:true;
}

template <typename T>
T* UniquePtr<T>::release(){
    T* __p=_p;
    _p=nullptr;   
    return __p;
}