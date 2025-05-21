#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	AForm	*a = new ShrubberyCreationForm();
	Bureaucrat	*toto;
	
	try
	{
		std::cout << *toto << std::endl;
		std::cout << *a << std::endl;
	}
	catch (AForm &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
