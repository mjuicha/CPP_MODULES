#include "Ice.hpp"

/************************* Orhodox Canonical Form *************************/

Ice::Ice() : AMateria("ice")
{}

Ice::Ice(const Ice &ICE)
{
    *this = ICE;
}

Ice &Ice::operator=(const Ice &ICE)
{
    if (this == &ICE)
        type = ICE.type;
    return *this;
}

Ice::~Ice()
{}

/************************* Member Functions *************************/

AMateria* Ice::clone() const
{
    AMateria *clone = new Ice(*this);
    return clone;
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}