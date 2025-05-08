#include <iostream>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "The memory address : " << &string << std::endl;
    std::cout << "The memory address : " << stringPTR << std::endl;
    std::cout << "The memory address : " << &stringREF << std::endl;

    std::cout << "The value : " << string << std::endl;
    std::cout << "The value : " << *stringPTR << std::endl;
    std::cout << "The value : " << stringREF << std::endl;
    return 0;
}