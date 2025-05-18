#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat*	toto = new Bureaucrat();

	try
	{
		std::cout << *toto << std::endl;
		toto->GradeTooLowException(toto->getGrade());
		toto->GradeTooHighException(toto->getGrade());
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	delete toto;
	return 0;
}
