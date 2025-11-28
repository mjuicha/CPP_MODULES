#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &RRF);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &RRF);
        ~RobotomyRequestForm();

        std::string getTarget() const;
        void execute(Bureaucrat const & executor) const;
};

#endif
