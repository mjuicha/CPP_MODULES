#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
    {
        Bureaucrat bureaucrat("BURO",11);
        Form form("FORM", 10, 5);
        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
	catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
	return (0);
}
