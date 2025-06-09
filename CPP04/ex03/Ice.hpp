#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice &ICE);
        Ice &operator=(const Ice &ICE);
        ~Ice();
        
        AMateria* clone() const;
        void use(ICharacter &target);
};

#endif
