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
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	return os;
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
	return this->_grade--;
}

int	Bureaucrat::upGrade()
{
	return this->_grade++;
}

void	Bureaucrat::GradeTooHighException(int grade)
{
	if (grade > 150)
		throw std::domain_error("The grade is too high.");
}

void	Bureaucrat::GradeTooLowException(int grade)
{
	if (grade < 1)
		throw std::domain_error("The grade is too low.");
}






