#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &PPF);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &PPF);
        ~PresidentialPardonForm();

        // getters
        std::string getTarget() const;
        // execute
        void execute(Bureaucrat const & executor) const;
};

#endif