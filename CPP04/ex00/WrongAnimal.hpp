#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& C);
        WrongAnimal& operator=(const WrongAnimal& C);
        ~WrongAnimal();

        std::string getType() const;
        void makeSound() const;
};

#endif
