#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon*      weap;
    public:
        HumanB(std::string str);
        
        void    setWeapon(Weapon& weeeap);
        void    attack( void );
};


#endif
