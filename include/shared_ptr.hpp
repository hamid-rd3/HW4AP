template <typename T>
SharedPtr<T>::SharedPtr(T* ptr)
    : _p { ptr }
{
    cnt = new size_t { 1 };
}

template <typename T>
SharedPtr<T>::SharedPtr()
{
    _p = nullptr;
    cnt = new size_t { 0 };
}

template <typename T>
T* make_shared(T t)
{
    return new T { t };
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
  if((*cnt)>1)
    {
        (*cnt)--;
        _p=nullptr;
    }
    else if ((*cnt)==1){
        delete _p;
        _p=nullptr;
        (*cnt)=0;
    }
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T>& ptr)
    : _p { ptr.get() }
    , cnt { ptr.cnt }
{
    (*cnt)++;
}

template <typename T>
SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<T>& ptr)
{
    if(ptr.get()==_p)
        return *this;
    delete _p;
    _p=ptr.get();
    cnt=ptr.cnt;
    (*cnt)++;
    return *this;
}

template <typename T>
const size_t& SharedPtr<T>::use_count() const
{
    return *cnt;
}
template <typename T>
void SharedPtr<T>::reset(){
    delete _p;
    _p=nullptr;
    (*cnt)=0;
}

template <typename T>
SharedPtr<T>::operator bool()const{
    return (_p==nullptr)?false:true;
}

template <typename T>
void SharedPtr<T>::reset(const T* t){
    delete _p;
    _p=new T {*t};
    (*cnt)=1;
}