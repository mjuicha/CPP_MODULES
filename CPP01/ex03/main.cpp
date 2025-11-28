#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{

    Weapon club = Weapon("crude spiked club");
    // test for const in getType
    std::string type = club.getType();
    type += " (test for const in getType)";
    std::cout << type << std::endl;


    return 0;
}