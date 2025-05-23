#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int	main()
{
	AForm	*a = new ShrubberyCreationForm();
	Bureaucrat	*toto = new Bureaucrat();

	std::cout << "------ ShrubberyCreationForm ------" << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << *toto << std::endl;
		std::cout << *a << std::endl;
		toto->signForm(*a);
		if (a->execute(*toto))
			toto->executeForm(*a);
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "----------------- -----------------" << std::endl;
	std::cout << std::endl;

	AForm *b = new RobotomyRequestForm();
	return (0);
}
