#include "PhoneBook.hpp"

void    is_valid_input(std::string input)
{
    PhoneBook PhoneBook;
    if (input == "ADD")
        PhoneBook.add();
    else if (input == "SEARCH")
        PhoneBook.search();
    else if (input == "EXIT")
        PhoneBook.exit();
}

int main()
{
    std::string input;
    while (1)
    {
        std::cout << "Welcome in med PhoneBook : ";
        std::getline(std::cin, input);
        is_valid_input(input);
    }
    return (0);
}