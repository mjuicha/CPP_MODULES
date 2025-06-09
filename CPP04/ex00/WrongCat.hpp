#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat& C);
        WrongCat& operator=(const WrongCat& C);
        ~WrongCat();

        void makeSound() const;
};

#endif
