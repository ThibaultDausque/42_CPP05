#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat*	toto = new Bureaucrat();

	toto->downGrade();
	try
	{
		std::cout << *toto << std::endl;
	}
	catch (const Bureaucrat::gradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (const Bureaucrat::gradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete toto;
	return 0;
}
