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
        Form(const std::string &name, int grade_to_sign, int grade_to_execute);
        Form(const Form& F);
        Form& operator=(const Form& F);
        ~Form();

        // member functions
        
        // getters
        int getGradeToSign() const;
        int getGradeToExecute() const;
        std::string getName() const;
        bool getIsSigned() const;

        // beSigned
        void beSigned(const Bureaucrat& B);

        int verifyGrade(int grade) const;

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

std::ostream& operator<<(std::ostream& o, const Form& F);

#endif