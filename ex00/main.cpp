#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat*	toto;

	try
	{
		std::cout << toto << std::endl;
	}
	catch (std::exception & e)
	{
		toto->GradeTooHighException(toto->getGrade());
		toto->GradeTooLowException(toto->getGrade());
	}
	return 0;
}
