#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"  
#include "WrongCat.hpp"

int main()
{
    const int nb = 2;
    const Animal *animals[nb];

    for (int i = 0; i < nb; ++i)
    {
        if (i < (nb / 2))
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << std::endl;

    for (int i = 0; i < nb; ++i)
        animals[i]->makeSound();
        
    std::cout << std::endl;
    
    for (int i = 0; i < nb; ++i)
        delete animals[i];

    std::cout << std::endl;
    std::cout << "Deep copy test" << std::endl;
    std::cout << std::endl;

    Cat basic;
	{
		Cat tmp = basic;
	}
    return 0;
}
