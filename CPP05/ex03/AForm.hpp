#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;

    public:
        AForm();
        AForm(std::string name, int grade_to_sign, int grade_to_execute);
        AForm(const AForm& F);
        AForm& operator=(const AForm& F);
        virtual ~AForm();

        // member functions
        virtual void execute(Bureaucrat const & executor) const = 0;
        void checkExecution(const Bureaucrat& executor) const;
        // getters
        int getGradeToSign() const;
        int getGradeToExecute() const;
        const std::string& getName() const;
        bool getIsSigned() const;

        // beSigned
        void beSigned(const Bureaucrat& B);

        // exceptions
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
        class FormNotSignedException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& o, const AForm& F);

#endif
