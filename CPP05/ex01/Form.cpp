#include "Form.hpp"

// Orthodox Form

Form::Form() : name("Unknown"), is_signed(false), grade_to_sign(1), grade_to_execute(1)
{}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute)
    : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
    if (grade_to_sign > MIN)
        throw Form::GradeTooLowException();
    if (grade_to_sign < MAX)
        throw Form::GradeTooHighException();
    if (grade_to_execute > MIN)
        throw Form::GradeTooLowException();
    if (grade_to_execute < MAX)
        throw Form::GradeTooHighException();
}

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
const std::string& Form::getName() const
{
    return name;
}
bool Form::getIsSigned() const
{
    return is_signed;
}

// beSigned
void Form::beSigned(const Bureaucrat& B)
{
   if (B.getGrade() <= grade_to_sign)
    {
        is_signed = true;
        std::cout << B.getName() << " signed " << name << std::endl;
    }
   else
       throw Form::GradeTooLowException();
}

// exceptions
const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: Grade too high";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: Grade too low";
}

// cout operator
std::ostream& operator<<(std::ostream& o, const Form& F)
{
    o << "Form: " << F.getName() << ", is signed: " << (F.getIsSigned() ? "yes" : "no")
      << ", grade to sign: " << F.getGradeToSign()
      << ", grade to execute: " << F.getGradeToExecute();
    return o;
}
