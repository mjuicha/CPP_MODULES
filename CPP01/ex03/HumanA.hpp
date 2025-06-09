#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon&     weap;
    public:
        HumanA(std::string str, Weapon& weeeap);
        void    attack( void );
};

#endif