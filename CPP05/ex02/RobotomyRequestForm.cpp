#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &RRF) : AForm(RRF)
{
    *this = RRF;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &RRF)
{
    if (this != &RRF)
        this->target = RRF.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    checkExecution(executor);
    std::cout << "BRRRRRRRRRRRRRRRRRRRRRTTTT" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << target << "'s robotomization failed" << std::endl;
}
