#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
	Intern someRandomIntern;
	AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	try
	{
		Bureaucrat bender("Bender", 1);
		bender.signForm(*rrf);
		bender.executeForm(*rrf);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	delete rrf;
	return 0;
}
