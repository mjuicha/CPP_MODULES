#include "Form.hpp"

// Orthodox Form

Form::Form() : name("Unknown"), is_signed(false), grade_to_sign(1), grade_to_execute(1)
{}

Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute)
    : name(name), is_signed(false) , grade_to_sign(verifyGrade(grade_to_sign)),
      grade_to_execute(verifyGrade(grade_to_execute))
{}

Form::Form(const Form& F) : name(F.name), is_signed(F.is_signed),
                             grade_to_sign(F.grade_to_sign), grade_to_execute(F.grade_to_execute)
{}

Form& Form::operator=(const Form& F)
{
    if (this != &F)
        this->is_signed = F.is_signed;
    return *this;
}

Form::~Form()
{}

// getters
int Form::getGradeToSign() const
{
    return grade_to_sign;
}
int Form::getGradeToExecute() const
{
    return grade_to_execute;
}
std::string Form::getName() const
{
    return name;
}
bool Form::getIsSigned() const
{
    return is_signed;
}

// verifyGrade
int Form::verifyGrade(int grade) const
{
    if (grade > MIN)
        throw Form::GradeTooLowException();
    if (grade < MAX)
        throw Form::GradeTooHighException();
    return grade;
}

// beSigned
void Form::beSigned(const Bureaucrat& B)
{
    if (B.getGrade() > grade_to_sign)
        throw Form::GradeTooLowException();
    is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade too high";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade too low";
}


std::ostream& operator<<(std::ostream& o, const Form& F)
{
    o << "Form: " << F.getName() << ", is signed: " << (F.getIsSigned() ? "yes" : "no")
      << ", grade to sign: " << F.getGradeToSign()
      << ", grade to execute: " << F.getGradeToExecute();
    return o;
}
