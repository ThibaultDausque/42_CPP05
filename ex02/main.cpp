#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
	std::cout << std::endl;
	std::cout << "----------------- -----------------" << std::endl;
	std::cout << std::endl;
	std::cout << "------ RobotomyRequestForm ------" << std::endl;
	std::cout << std::endl;
	AForm *b = new RobotomyRequestForm();
	Bureaucrat *tutu = new Bureaucrat();
	try
	{
		std::cout << *tutu << std::endl;
		std::cout << *b << std::endl;
		tutu->signForm(*b);
		if (b->execute(*tutu))
			tutu->executeForm(*b);
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
	std::cout << std::endl;
	std::cout << "----------------- -----------------" << std::endl;
	std::cout << std::endl;
	std::cout << "------ PresidentialPardonForm ------" << std::endl;
	AForm	*c = new PresidentialPardonForm();
	Bureaucrat	*tata = new Bureaucrat();
	try
	{
		std::cout << *tata << std::endl;
		std::cout << *c << std::endl;
		tutu->signForm(*c);
		if (c->execute(*tata))
			tutu->executeForm(*c);
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
	std::cout << std::endl;
	std::cout << "----------------- -----------------" << std::endl;
	delete a;
	delete b;
	delete c;
	delete toto;
	delete tutu;
	delete tata;
	return (0);
}
