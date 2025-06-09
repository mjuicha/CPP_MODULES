#include "Dog.hpp"

/********************** Orthodox Canonical Form **********************/

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& D)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = D;
}

Dog& Dog::operator=(const Dog& D)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &D)
        type = D.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

/********************** Member Functions **********************/

void Dog::makeSound() const
{
    std::cout << "Dog : Woof Woof" << std::endl;
}
