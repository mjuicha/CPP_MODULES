#include "Array.hpp"

template <typename T> Array<T>::Array() : arr(NULL), size_(0)
{}

template <typename T> Array<T>::Array(unsigned int n) : size_(n)
{
    if (n > 0)
        this->arr = new T[n];
    else
        this->arr = NULL;
}

template <typename T> Array<T>::Array(const Array &other) : size_(other.size_)
{
    if (size_ > 0)
    {
        this->arr = new T[size_];
        for (unsigned int i = 0; i < size_; i++)
            this->arr[i] = other.arr[i];
    }
    else
        this->arr = NULL;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete [] this->arr;
        this->size_ = other.size();
        this->arr = new T[size_];
        if (size_ > 0)
        {
            this->arr = new T[size_];
            for (unsigned int i = 0; i < size_; i++)
                this->arr[i] = other.arr[i];
        }
        else
            this->arr = NULL;
    }
    return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int index)
{
    if (index >= this->size() || index < 0)
        throw std::out_of_range("Index out of bounds");
    return this->arr[index];
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= this->size() || index < 0)
        throw std::out_of_range("Index out of bounds");
    return this->arr[index];
}

template <typename T> Array<T>::~Array()
{
    delete [] this->arr;
}
