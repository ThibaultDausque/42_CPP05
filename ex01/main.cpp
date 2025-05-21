#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat	toto;
	Form	note;

	try
	{
		std::cout << toto << std::endl;
		toto.signForm(note);
		std::cout << note;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException& f)
	{
		std::cerr << f.what() << std::endl;
	}
	catch (Form::GradeTooLowException& g)
	{
		std::cerr << g.what() << std::endl;
	}
	return 0;
}
