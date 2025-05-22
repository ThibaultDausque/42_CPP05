#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	AForm	*a = new ShrubberyCreationForm();
	Bureaucrat	*toto = new Bureaucrat();
	
	try
	{
		std::cout << *toto << std::endl;
		std::cout << *a << std::endl;
	}
	catch (AForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
