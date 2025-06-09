#include "Dog.hpp"

/********************** Orthodox Canonical Form **********************/

Dog::Dog()
{
    brain = new Brain();
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& D)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*D.brain);
    type = D.type;
}

Dog& Dog::operator=(const Dog& D)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &D)
    {
        delete brain;
        brain = new Brain(*D.brain);
        type = D.type;
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

/********************** Member Functions **********************/

void Dog::makeSound() const
{
    std::cout << "Dog : Woof Woof" << std::endl;
}
