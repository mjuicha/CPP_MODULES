#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
    private:
        Contact Contact[7];
    public:
        void    add(){
            std::cout << "you write ADD" << std::endl;
        }
        void    search(){
            std::cout << "you write SEARCH" << std::endl;
        }
        void    exit(){
            std::exit(0);
        }
};









#endif
