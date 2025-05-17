#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
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
		this->_grade = src._grade;
	return *this;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& src)
{
	(void) os;
	(void) src;
	// os << src.getName() << ", bureaucrat grade " << src.getGrade() << ".";
	os << "Hello !";
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
		std::cout << "The grade of " << this->_name << " is too high." << std::endl;
}

void	Bureaucrat::GradeTooLowException(int grade)
{
	if (grade < 1)
		std::cout << "The grade of " << this->_name << " is too low." << std::endl;
}






