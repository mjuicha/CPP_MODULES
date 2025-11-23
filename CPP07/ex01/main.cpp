#include "iter.hpp"

void print(std::string &s)
{
    std::cout << s << "* *";
}

int main()
{
    std::string dfk[] = {"Diha", "f", "k"};
    iter(dfk, 3, print);
    std::cout << std::endl;
}