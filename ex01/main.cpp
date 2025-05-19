#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat*	toto = new Bureaucrat();
	Form*	note = new Form();

	try
	{
		std::cout << *toto << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch ()
	delete toto;
	return 0;
}
