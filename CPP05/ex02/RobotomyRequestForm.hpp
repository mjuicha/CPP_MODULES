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

        // getters
        std::string getTarget() const;
        // execute
        void execute(Bureaucrat const & executor) const;
};

#endif
