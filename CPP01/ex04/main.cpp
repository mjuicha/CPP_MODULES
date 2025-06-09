#include "replace.hpp"

int main(int ac, char **av)
{
    if (ac != 4)
        return error(0);
    return run(av);
}
