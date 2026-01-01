#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <iostream>

template <typename T> void  easyfind(T &container, int value)
{
    if (std::find(container.begin(), container.end(), value) != container.end())
        std::cout << "Found " << value << std::endl;
    else
        std::cout << "Not Found " << value << std::endl;
};

#endif

