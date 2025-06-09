#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string str);
        FragTrap(const FragTrap &ct);
        FragTrap &operator=(const FragTrap &ct);
        ~FragTrap();

        void highFivesGuys(void);
};

#endif
