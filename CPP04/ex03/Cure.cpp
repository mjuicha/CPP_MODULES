#include "Cure.hpp"

/************************* Orhodox Canonical Form *************************/

Cure::Cure() : AMateria("cure")
{}

Cure::Cure(const Cure &CURE)
{
    *this = CURE;
}

Cure &Cure::operator=(const Cure &CURE)
{
    if (this != &CURE)
        type = CURE.type;
    return *this;
}

Cure::~Cure()
{}

/************************* Member Functions *************************/

AMateria *Cure::clone() const
{
    AMateria *clone = new Cure(*this);
    return clone;
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
