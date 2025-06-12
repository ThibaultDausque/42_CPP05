#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("toto")
{
	this->_grade = 50;
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

int	Bureaucrat::signForm(Form &src)
{
	if (src.beSigned(*this) == 1)
	{
		std::cout << this->getName() << " sign " << src.getName() << std::endl;
		return 1;
	}
	else if (src.beSigned(*this) == 0)
	{
		std::cout << this->getName() << " couldn't sign " << src.getName()
			<< " because he is dumb as fuck." << std::endl;
		return 1;
	}
	return 0;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "* grade too high *";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "* grade too low *";
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

