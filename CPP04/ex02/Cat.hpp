#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    private:
        Brain* brain;
    public:
        Cat();
        Cat(const Cat& C);
        Cat& operator=(const Cat& C);
        ~Cat();

        void makeSound() const;
};

#endif
