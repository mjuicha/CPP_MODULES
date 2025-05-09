#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon&     club;
    public:
        void    attack( void );
        HumanA(std::string str, Weapon  &weap): name(str), club(weap){}
};

#endif