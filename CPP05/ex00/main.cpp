#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat B1("low", 149);
    Bureaucrat B2("high", 1);
    std::cout << B1 << std::endl;
    std::cout << B2 << std::endl;
    try
    {
        B1.dec_grade();
        B2.inc_grade();
    }
    catch (std::exception & e)
    {
        std::cout << "catching : " << e.what();
    }
    return 0;
}
