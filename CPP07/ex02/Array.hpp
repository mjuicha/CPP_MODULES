#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
    private:
        T *arr;
        unsigned int size_;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        int & operator[]( int index);
        ~Array();

        T size() const;
};

#endif