#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& A);
        Animal& operator=(const Animal& A);
        virtual ~Animal();

        std::string getType() const;
        virtual void makeSound() const;
};

#endif

