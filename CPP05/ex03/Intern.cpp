#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{}

// member function

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}


AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    std::string formTypes[3] =
    {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon"
    };
    AForm *forms[3] =
    {
        new RobotomyRequestForm(target),
        new ShrubberyCreationForm(target),
        new PresidentialPardonForm(target)
    };
    try
    {
        for (int i = 0; i < 3; i++)
        {
            if (formName == formTypes[i])
            {
                std::cout << "Intern creates " << formName << " form." << std::endl;
                return forms[i];
            }
        }
        throw Intern::FormNotFoundException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return NULL;
}