#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
        ScalarConverter::convert(av[1]);
    else
        std::cerr << "Usage: " << av[0] << " <input>" << std::endl;
    return 0;
}
