#include "Bureaucrat.hpp"

// Orthodox AForm

Bureaucrat::Bureaucrat() : name("Unknown"), grade(1)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade > MIN)
        throw Bureaucrat::GradeTooLowException();
    if (grade < MAX)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& B) : name(B.name), grade(B.grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& B)
{
    this->grade = B.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& B)
{
    o << B.getName() << ", bureaucrat grade " << B.getGrade() << ".";
    return o;
}

// member functions

std::string Bureaucrat::getName() const
{
    return name;
}
int Bureaucrat::getGrade() const
{
    return grade;
}

int Bureaucrat::inc_grade()
{
    grade--;
    std::cout << "increment " << grade << std::endl;
    if (grade < MAX)
        throw Bureaucrat::GradeTooHighException();
    return grade;
}
int Bureaucrat::dec_grade()
{
    grade++;
    std::cout << "decrement " << grade << std::endl;
    if (grade > MIN)
        throw Bureaucrat::GradeTooLowException();
    return grade;
}

// signForm
void Bureaucrat::signForm(AForm& F) const
{
    try
    {
        F.beSigned(*this);
        std::cout << getName() << " signs " << F << std::endl;
    }
    catch (const AForm::GradeTooLowException& e)
    {
        std::cout << getName() << " cannot sign " << F << " because: " << e.what() << std::endl;
    }
}

// executeForm

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << getName() << " executes " << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << getName() << " cannot execute " << form << " because: " << e.what() << std::endl;
    }
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high.";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low.";
}
