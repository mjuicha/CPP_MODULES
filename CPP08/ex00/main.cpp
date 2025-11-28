#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> vec;
        for (int i = 0; i < 10; ++i)
            vec.push_back(i * 10);
        easyfind(vec, 30);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}