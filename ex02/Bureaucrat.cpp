#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("toto")
{
	this->_grade = 1;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy): _name("toto")
{
	*this = cpy;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		this->_grade = src.getGrade();
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& src)
{
	if (src.getGrade() > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return os;
	}
	else if (src.getGrade() < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return os;
	}
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return os;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "* grade too high *";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "* grade too low *";
}

int	Bureaucrat::signForm(AForm &src)
{
	if (this->getGrade() <= src.signGrade())
	{
		std::cout << this->getName() << " sign " << src.getName() << std::endl;
		src.beSigned(*this);
		return 1;
	}
	std::cout << this->getName() << " couldn't sign " << src.getName()
		<< " because he is dumb as fuck." << std::endl;
	return 0;
}

int	Bureaucrat::executeForm(AForm const & form) const
{
	if (form.getSigned())
	{
		std::cout << this->_name << " executed " << form.getName() << std::endl;
		return 1;
	}
	std::cout << this->_name << " can't execute " << form.getName() << std::endl;
	return 0;
}

const std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

int	Bureaucrat::downGrade()
{
	return this->_grade++;
}

int	Bureaucrat::upGrade()
{
	return this->_grade--;
}

