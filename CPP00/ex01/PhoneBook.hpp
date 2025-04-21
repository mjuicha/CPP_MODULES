#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>
# include <sstream> 

class PhoneBook
{
    private:
        Contact Contacts[8];
    public:
        static int  phBk_number;
        void        add();
        void        search();
        void        exit();
        void        init_contact();
        void        list_table();
        void        show_valid_contact(int i);
        void        choose_to_display();
};









#endif








