#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{   
    for (int i = 0; i < 4; ++i)
        _materias[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    for (int i = 0; i < 4; ++i)
        _materias[i] = src._materias[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    if (this != &src)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (_materias[i])
                delete _materias[i];
            if (src._materias[i])
                _materias[i] = src._materias[i]->clone();
            else
                _materias[i] = 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        if (_materias[i])
            delete _materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (!materia)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (_materias[i] == 0)
        {
            _materias[i] = materia;
            return;
        }
    }
    delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    return 0;
}
