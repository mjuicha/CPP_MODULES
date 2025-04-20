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
    if (str[i] == '+')
    {
        if (!str[i + 1])
            return false;
        i++;
    }
    while (str[i])
    {
        if  (!isdigit(str[i]))
            return false;
        i++;
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
    Contacts[phBk_number].set_contact(1);
    Contacts[phBk_number].set_first_name(first_name);
    Contacts[phBk_number].set_last_name(last_name);
    Contacts[phBk_number].set_nickname(nickname);
    Contacts[phBk_number].set_phone_number(phone_number);
    Contacts[phBk_number].set_darkest_secret(darkest_secret);
}

void    show_empty_contact(int i)
{
    std::cout << std::right << std::setfill(' ') << std::setw(10) << i << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(11) << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(11) << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(11) << '\n';
}

void    PhoneBook::show_valid_contact(int i)
{
    std::cout << std::right << std::setfill(' ') << std::setw(10) << i << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(10) << Contacts[i].get_firstname() << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(10) << Contacts[i].get_lastname() << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(10) << Contacts[i].get_nickname() << '\n';
}

void    PhoneBook::list_table()
{
    int i = 0;
    while (i < 8)
    {
        if (!Contacts[i].get_setted())
            show_empty_contact(i);
        else
            show_valid_contact(i);
        i++;
    }
}

void    choose_to_display()
{
    std::string str;
    std::cout << "Enter the index of the contact to display: ";
    std::getline(std::cin, str);


}

void    PhoneBook::search()
{
    list_table();
    choose_to_display();
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

void    PhoneBook::init_contact()
{
    int i = -1;

    while (++i < 8)
        Contacts[i].set_contact(0);
}

void    phonebook_input()
{
    PhoneBook PhoneBook;
    std::string input;
    PhoneBook.init_contact();
    while (1)
    {
        input = get_phonebook_input(input);
        if (input == "ADD")
        {
            PhoneBook.add();
            // PhoneBook.listall();
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
