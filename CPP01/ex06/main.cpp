#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    if (ac != 2)
    {
        std::cerr << "INVALID ARGUMENT" << std::endl;
        return 1;
    }
    std::string level = av[1];
    harl.complain(level);
    return 0;
}