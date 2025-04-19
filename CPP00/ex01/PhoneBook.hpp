#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact Contacts[8];
    public:
        static int  phBk_number;
        void        add();
        void        search();
        void        exit();
};









#endif








