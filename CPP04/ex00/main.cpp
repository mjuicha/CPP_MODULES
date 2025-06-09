#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"  
#include "WrongCat.hpp"

int main()
{
    
    /************ Animal ************/

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;

    delete meta;
    delete i;
    delete j;

    std::cout << std::endl;
    std::cout << "***********************************" << std::endl;

    /************ Wrong Animal ************/

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << std::endl;

    std::cout << wrongCat->getType() << " " << std::endl;

    std::cout << std::endl;

    wrongCat->makeSound();
    wrongMeta->makeSound();

    std::cout << std::endl;

    delete wrongMeta;
    delete wrongCat;
    return 0;
}
