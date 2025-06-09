#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& D);
        Dog& operator=(const Dog& D);
        ~Dog();
    
        void makeSound() const;
};

#endif
