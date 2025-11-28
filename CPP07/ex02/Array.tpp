#include "Array.hpp"

template <typename T> Array<T>::Array()
{
    this->arr = nullptr;
    size_ = 0;
    std::cout << "Default constructor called" << std::endl;
    std::cout << "Array of size " << size_ << " created." << std::endl;
}

template <typename T> Array<T>::Array(unsigned int n)
{
    this->arr = new T[n];
    size_ = n;
    std::cout << "Parameterized constructor called" << std::endl;
    std::cout << "Array of size " << size_ << " created." << std::endl;
}

template <typename T> Array<T>::Array(const Array &other)
{
    this->size_ = other.size();
    this->arr = new T[size_];
    for (unsigned int i = 0; i < size_; i++)
        this->arr[i] = other.arr[i];
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete this->arr;
        this->size_ = other.size();
        this->arr = new T[size_];
        for (unsigned int i = 0; i < size_; i++)
            this->arr[i] = other.arr[i];
    }
    return *this;
}

template <typename T> int & Array<T>::operator[](int index)
{
    if (index >= this->size() || index < 0)
        throw std::out_of_range("Index out of bounds");
    return this->arr[index];
}

template <typename T> T Array<T>::size() const
{
    return this->size_;
}

template <typename T> Array<T>::~Array()
{
    delete [] this->arr;
}