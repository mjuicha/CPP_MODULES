#include "Bureaucrat.hpp"

// Orthodox Canonical Form

Bureaucrat::Bureaucrat() : name("Unknown"), grade(1)
{}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade > MIN)
        throw Bureaucrat::GradeTooLowException();
    if (grade < MAX)
        throw Bureaucrat::GradeTooHighException();
    this->grade = grade;
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

// member functions

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::inc_grade()
{
    if (grade == MAX)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::dec_grade()
{
    if (grade == MIN)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high.";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low.";
}

void Bureaucrat::signForm(Form& F)
{
    try
    {
        F.beSigned(*this);
        std::cout << getName() << " signed " << F.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << getName() << " cannot sign " << F.getName() << " because: " << e.what() << "." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& B)
{
    o << B.getName() << ", bureaucrat grade " << B.getGrade() << ".";
    return o;
}
