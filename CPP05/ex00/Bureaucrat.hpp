#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define MAX 1
#define MIN 150

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& B);
        Bureaucrat& operator=(const Bureaucrat& B);
        ~Bureaucrat();

        // member functions
        int inc_grade();
        int dec_grade();

        // getters
        int getGrade() const;
        std::string getName() const;

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

std::ostream&   operator<<(std::ostream& o, const Bureaucrat& B);

#endif