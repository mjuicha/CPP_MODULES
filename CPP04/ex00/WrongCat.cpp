#include "WrongCat.hpp"

/********************** Orthodox Canonical Form **********************/

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& C)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    type = C.type;
}

WrongCat& WrongCat::operator=(const WrongCat& C)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &C)
        type = C.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

/********************** Member Functions **********************/

void WrongCat::makeSound() const
{
    std::cout << "WrongCat : Meow!!! Meow!!!" << std::endl;
}
