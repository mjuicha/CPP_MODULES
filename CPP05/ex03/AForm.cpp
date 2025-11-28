#include "AForm.hpp"

// Orthodox Canonical Form

AForm::AForm() : name("Unknown"), is_signed(false), grade_to_sign(1), grade_to_execute(1)
{}

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute)
    : name(name), is_signed(false), grade_to_sign(verifyGrade(grade_to_sign)),
      grade_to_execute(verifyGrade(grade_to_execute))
{}

AForm::AForm(const AForm& F) : name(F.name), is_signed(F.is_signed),
                             grade_to_sign(F.grade_to_sign), grade_to_execute(F.grade_to_execute)
{}

AForm& AForm::operator=(const AForm& F)
{
    if (this != &F)
        this->is_signed = F.is_signed;
    return *this;
}

AForm::~AForm()
{}

int AForm::verifyGrade(int grade) const
{
    if (grade > MIN)
        throw AForm::GradeTooLowException();
    if (grade < MAX)
        throw AForm::GradeTooHighException();
    return grade;
}

// getters
int AForm::getGradeToSign() const
{
    return grade_to_sign;
}
int AForm::getGradeToExecute() const
{
    return grade_to_execute;
}
std::string AForm::getName() const
{
    return name;
}
bool AForm::getIsSigned() const
{
    return is_signed;
}

// beSigned
void AForm::beSigned(const Bureaucrat& B)
{
    if (B.getGrade() > grade_to_sign)
        throw AForm::GradeTooLowException();
    is_signed = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > grade_to_execute)
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm: Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm: Form not signed";
}

std::ostream& operator<<(std::ostream& o, const AForm& F)
{
    o << "AForm: " << F.getName() << ", is signed: " << (F.getIsSigned() ? "yes" : "no")
      << ", grade to sign: " << F.getGradeToSign()
      << ", grade to execute: " << F.getGradeToExecute();
    return o;
}
