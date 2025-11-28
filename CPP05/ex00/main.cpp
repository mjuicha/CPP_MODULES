#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat B1("low", 150);
        Bureaucrat B2("high", 3);
        std::cout << B1 << std::endl;
        std::cout << B2 << std::endl;
        B1.dec_grade();
        B2.inc_grade();
        std::cout << B1 << std::endl;
        std::cout << B2 << std::endl;
    }
    catch (int n)
    {
        std::cerr << "catching exception: " << std::endl;
    }
    return 0;
}
