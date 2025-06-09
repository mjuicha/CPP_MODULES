#include "Cat.hpp"

/********************** Orthodox Canonical Form **********************/

Cat::Cat()
{
    brain = new Brain();
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& C)
{
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*C.brain);
    type = C.type;
}

Cat& Cat::operator=(const Cat& C)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &C)
    {
        delete brain;
        brain = new Brain(*C.brain);
        type = C.type;
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

/********************** Member Functions **********************/

void Cat::makeSound() const
{
    std::cout << "Cat : Meow Meow" << std::endl;
}
