#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define MAX 1
#define MIN 150

#include <iostream>
#include <exception>

#inclt std::string name;
        int grade;
    
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat& B);
        Bureaucrat& operator=(const Bureaucrat& B);
        ~Bureaucratude "Form.hpp"

class Form;
class Bureaucrat
{
    private:
        cons();

        // member functions
        void inc_grade();
        void dec_grade();

        // getters
        int getGrade() const;
        std::string getName() const;

        // signForm
        void signForm(Form& F);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream&   operator<<(std::ostream& o, const Bureaucrat& B);

#endif