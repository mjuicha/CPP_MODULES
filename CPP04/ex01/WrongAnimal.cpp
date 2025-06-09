#include "WrongAnimal.hpp"

/********************** Orthodox Canonical Form **********************/

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& C)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    type = C.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& C)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &C)
        type = C.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

/********************** Member Functions **********************/

std::string WrongAnimal::getType() const
{
    return type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal : Generic sound!" << std::endl;
}
