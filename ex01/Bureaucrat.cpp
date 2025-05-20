#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("toto")
{
	this->_grade = 42;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy)
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
	if (this->getGrade() == src.execGrade()
		&& this->getGrade() == src.signGrade())
	{
		std::cout << this->getName() << " sign " << src.getName() << std::endl;
		src.beSigned(*this);
		return 1;
	}
	std::cout << this->getName() << " couldn't sign " << src.getName()
		<< " because he is dumb as fuck." << std::endl;
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

