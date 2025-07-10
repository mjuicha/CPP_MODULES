#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;

    public:
        Form();
        Form(std::string name, int grade_to_sign, int grade_to_execute);
        Form(const Form& F);
        Form& operator=(const Form& F);
        ~Form();

        // member functions
        
        int getGradeToSign() const;
        int getGradeToExecute() const;
        const std::string& getName() const;
        bool getIsSigned() const;

        void beSigned(const Bureaucrat& B);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& o, const Form& F);

#endif