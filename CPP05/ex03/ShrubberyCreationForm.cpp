#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("default") 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target) 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &SCF) : AForm(SCF)
{
    *this = SCF;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &SCF)
{
    if (this != &SCF)
        this->target = SCF.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    std::ofstream outfile;

    checkExecution(executor);
    outfile.open(this->target + "_shrubbery");
    if (!outfile.is_open())
        throw std::runtime_error("Failed to open file");
    outfile << TREE;
    outfile.close();
}
