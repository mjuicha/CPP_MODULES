#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <iostream>

template <typename T> void  easyfind(T &container, int Int)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == Int)
        {
            std::cout << "Found: " << Int << std::endl;
            return;
        }
    }
    throw std::runtime_error("Value not found");
};


#endif