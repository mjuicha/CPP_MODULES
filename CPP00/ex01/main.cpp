#include "PhoneBook.hpp"
#include <cctype>

// Reference is when we add & like here in str

bool    white_space(std::string str)
{
    return std::all_of(str.begin(), str.end(), isspace);
}

bool    is_number(std::string str)
{
    int i = 0;
    if (str[i] == '+' && !str[i + 1])
        return false;
    i++;
    while (str[i])
    {
        if  (!isdigit(str[i]))
            return false;
    }
    return true;
}

std::string    get_line(std::string msg)
{
    std::string str;
    std::cout << msg;
    std::getline(std::cin, str);
    if (str.empty() || white_space(str))
    {
        std::cout << "invalid input" << std::endl;
        str = get_line(msg);
    }
    return str;
}

std::string    get_phone_number(std::string msg)
{
    std::string str;
    std::cout << msg;
    std::getline(std::cin, str);
    if (str.empty() || white_space(str) || !is_number(str))
    {
        std::cout << "invalid input" << std::endl;
        str = get_phone_number(msg);
    }
    return str;
}

void    PhoneBook::add()
{
    std::string first_name = get_line("enter first name : ");
    std::string last_name = get_line("enter last name : ");
    std::string nickname = get_line("enter nickname : ");
    std::string phone_number = get_phone_number("enter phone number : ");
    std::string darkest_secret = get_line("enter darkest secret : ");
    // here i want to set the vars in phonebook it has his elements like the naming up here
    Contacts[phBk_number].set_first_name(first_name);
    Contacts[phBk_number].set_last_name(last_name);
    Contacts[phBk_number].set_nickname(nickname);
    Contacts[phBk_number].set_phone_number(phone_number);
    Contacts[phBk_number].set_darkest_secret(darkest_secret);
}

void    PhoneBook::search()
{
    std::cout << "you write SEARCH" << std::endl;
}

void    PhoneBook::exit()
{
    std::exit(0);
}
int PhoneBook::phBk_number = 0;

std::string get_phonebook_input(std::string input)
{
    std::cout << "Welcome in med PhoneBook : ";
    std::getline(std::cin, input);
    return input;
}

void    phonebook_input()
{
    PhoneBook PhoneBook;
    std::string input;
    while (1)
    {
        input = get_phonebook_input(input);
        if (input == "ADD")
        {
            PhoneBook.add();
            PhoneBook.phBk_number++;
            if (PhoneBook.phBk_number == 8)
                PhoneBook.phBk_number = 0;
        }
        else if (input == "SEARCH")
            PhoneBook.search();
        else if (input == "EXIT")
            PhoneBook.exit();
    }
}

int main()
{
    phonebook_input();
    return (0);
}
