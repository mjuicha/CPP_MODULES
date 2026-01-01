#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;

    for (int i = 1; i <= 10; ++i)
        vec.push_back(i);
    easyfind(vec, 5);
    easyfind(vec, 15);
    return 0;
}
