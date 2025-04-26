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
        int         is_setted;
    public:
        void    set_first_name(std::string name);
        void    set_last_name(std::string name);
        void    set_nickname(std::string name);
        void    set_phone_number(std::string name);
        void    set_darkest_secret(std::string name);

        std::string get_firstname();
        std::string get_lastname();
        std::string get_nickname();
        std::string get_phonenumber();
        std::string get_darkestsecret();
        void set_contact(int i);
        int get_setted();
};

#endif

