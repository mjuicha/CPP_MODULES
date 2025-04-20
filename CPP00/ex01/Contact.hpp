#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "PhoneBook.hpp"
# include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        int is_setted;
    public:
        void    set_first_name(std::string name)
        {
            first_name = name;
        }
        void    set_last_name(std::string name)
        {
            last_name = name;
        }
        void    set_nickname(std::string name)
        {
            nickname = name;
        }
        void    set_phone_number(std::string name)
        {
            phone_number = name;
        }
        void    set_darkest_secret(std::string name)
        {
            darkest_secret = name;
        }

        std::string get_firstname()
        {
            return first_name;
        }
        std::string get_lastname()
        {
            return last_name;
        }
        std::string get_nickname()
        {
            return nickname;
        }
        std::string get_phonenumber()
        {
            return phone_number;
        }
        std::string get_darkestsecret()
        {
            return darkest_secret;
        }
        void set_contact(int i)
        {
            is_setted = i;
        }
        int get_setted()
        {
            return is_setted;
        }
};

#endif

