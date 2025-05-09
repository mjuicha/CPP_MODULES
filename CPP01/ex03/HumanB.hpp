#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon*      weap;
    public:
        void    attack( void );
        HumanB(std::string str);
        HumanB(std::string str, Weapon &club);
        void    setWeapon(Weapon &weeep);
};


#endif