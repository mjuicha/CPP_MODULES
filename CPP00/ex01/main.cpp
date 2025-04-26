#include "PhoneBook.hpp"
#include <cctype>

// Reference is when we add & like here in str

bool    white_space(std::string str)
{
    return std::all_of(str.begin(), str.end(), isspace);
}

bool    is_number(std::string str)
{
    size_t i = 0;
    if (str[i] == '+')
    {
        if (str.length() == 1)
            return false;
        i++;
    }
    while (i < str.length())
    {
        if  (!std::isdigit(str[i]))
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

void    set_index()
{
    PhoneBook::_index++;
    if (PhoneBook::_index == 8)
        PhoneBook::_index = 0;
}

void    PhoneBook::add()
{
    std::string first_name = get_line("enter first name : ");
    std::string last_name = get_line("enter last name : ");
    std::string nickname = get_line("enter nickname : ");
    std::string phone_number = get_phone_number("enter phone number : ");
    std::string darkest_secret = get_line("enter darkest secret : ");

    Contacts[_index].set_contact(1);
    Contacts[_index].set_first_name(first_name);
    Contacts[_index].set_last_name(last_name);
    Contacts[_index].set_nickname(nickname);
    Contacts[_index].set_phone_number(phone_number);
    Contacts[_index].set_darkest_secret(darkest_secret);
    set_index();
}

void    show_empty_contact(int i)
{
    std::cout << std::right << std::setfill(' ') << std::setw(10) << i << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(11) << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(11) << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(11) << '\n';
}

std::string ten_char(std::string str)
{
    if (str.length() <= 10)
        return str;
    str.resize(10);
    str[9] = '.';
    return str;
}

void    PhoneBook::show_valid_contact(int i)
{
    std::cout << std::right << std::setfill(' ') << std::setw(10) << i << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(10) <<  ten_char(Contacts[i].get_firstname()) << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(10) <<  ten_char(Contacts[i].get_lastname()) << '|';
    std::cout << std::right << std::setfill(' ') << std::setw(10) <<  ten_char(Contacts[i].get_nickname()) << '\n';
}

void    PhoneBook::show_table()
{
    int i = 0;
    while (i < 8)
    {
        if (Contacts[i].get_setted() == 0)
            show_empty_contact(i);
        else
            show_valid_contact(i);
        i++;
    }
}

void    PhoneBook::choose_to_display()
{
    std::string str;
    std::cout << "Enter the index of the contact to display:  ";
    std::getline(std::cin, str);
    if (str.empty() || !is_number(str))
    {
        std::cout << "invalid index !" << std::endl;
        return ;
    }
    int index;
    std::stringstream ss;
    ss << str;
    ss >> index;
    if (!(index > -1 && index < 8))
    {
        std::cout << "invalid index !" << std::endl;
        return ;
    }
    if (Contacts[index].get_setted() == 0)
        std::cout << "invalid is empty !" << std::endl;
    else
    {
        std::cout << std::left << std::setw(14) <<  "First name" <<  ": " << Contacts[index].get_firstname() << std::endl;
        std::cout << std::left << std::setw(14) <<  "Last name" <<  ": " << Contacts[index].get_lastname() << std::endl;
        std::cout << std::left << std::setw(14) <<  "Nickname" <<  ": " << Contacts[index].get_nickname() << std::endl;
        std::cout << std::left << std::setw(14) <<  "Number Phone" <<  ": " << Contacts[index].get_phonenumber() << std::endl;
        std::cout << std::left << std::setw(14) <<  "Darkest Secret" <<  ": " << Contacts[index].get_darkestsecret() << std::endl;
    }
}

void    PhoneBook::search()
{
    show_table();
    choose_to_display();
}

int PhoneBook::_index = 0;

std::string display_prompt(std::string input)
{
    std::cout << "Welcome in med PhoneBook : ";
    std::getline(std::cin, input);
    return input;
}

// special 
int Contact::get_setted()
{
    return is_setted;
}

void Contact::set_contact(int i)
{
    is_setted = i;
}
/**************/
// setters
/**************/

void    Contact::set_first_name(std::string name)
{
    first_name = name;
}

void    Contact::set_last_name(std::string name)
{
    last_name = name;
}

void    Contact::set_nickname(std::string name)
{
    nickname = name;
}

void    Contact::set_phone_number(std::string name)
{
    phone_number = name;
}

void    Contact::set_darkest_secret(std::string name)
{
    darkest_secret = name;
}

/**************/
// getters
/**************/
std::string Contact::get_firstname()
{
    return first_name;
}

std::string Contact::get_lastname()
{
    return last_name;
}

std::string Contact::get_nickname()
{
    return nickname;
}

std::string Contact::get_phonenumber()
{
    return phone_number;
}

std::string Contact::get_darkestsecret()
{
    return darkest_secret;
}



PhoneBook::PhoneBook()
{
    int i = -1;
    while (++i < 8)
        Contacts[i].set_contact(0);
}

void    PhoneBook::run()
{
    std::string input;
    while (1)
    {
        input = display_prompt(input);
        if (input == "ADD")
            add();
        else if (input == "SEARCH")
            search();
        else if (input == "EXIT")
            return ;
    }
}

int main()
{
    PhoneBook PhoneBook;
    PhoneBook.run();
    return 0;
}
