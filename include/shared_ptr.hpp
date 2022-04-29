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
    if (!_p) {
        delete cnt;
        cnt=nullptr;
        delete _p;
        _p = nullptr;
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
    delete _p;
    _p = new T { *ptr.get() };
}

template <typename T>
const size_t& SharedPtr<T>::use_count() const
{
    return *cnt;
}
