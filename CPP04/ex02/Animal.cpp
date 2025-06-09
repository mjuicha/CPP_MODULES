#include "Animal.hpp"

/********************** Orthodox Canonical Form **********************/

Animal::Animal() : type("Unknown")
{
    std::cout << "Animal constructor is called" << std::endl;
}

Animal::Animal(const Animal& A)
{
    std::cout << "Animal copy constructor is called" << std::endl;
    type = A.type;
}

Animal& Animal::operator=(const Animal& A)
{
    std::cout << "Animal assignment operator is called" << std::endl;
    if (this != &A)
        type = A.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor is called" << std::endl;
}

/********************** Member Functions **********************/

std::string Animal::getType() const
{
    return type;
}
