#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *arr, const int size, void (*f)( T &))
{
    for (int i = 0; i < size; i++)
        f(arr[i]);
}

template <typename T> void iter(T *arr, const int size, void (*f)( const T &))
{
    for (int i = 0; i < size; i++)
        f(arr[i]);
}

template <typename T> void print(T &s)
{
    std::cout << s << " ";
}

template <typename T> void increment(T &n)
{
    n++;
}

#endif