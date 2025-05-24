#include "RobotomyRequestForm.hpp"
#include <ostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotRequestForm", 0, 72, 45)
{
	this->_target = "tutu";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotRequestForm", 0, 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : AForm(cpy)
{
	*this = cpy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
	{
		this->_signed = src._signed;
		this->_target = src._target;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& src)
{
	if (src.signGrade() < 1 || src.execGrade() < 1)
	{
		throw AForm::GradeTooHighException();
		return os;
	}
	else if (src.signGrade() > 150 || src.execGrade() > 150)
	{
		throw AForm::GradeTooLowException();
		return os;
	}
	os << "RobotomyRequestForm " << src.getName() << ", sign grade " << src.signGrade()
		<< ", exec grade " << src.execGrade() << ".";
	return os;
}

int	RobotomyRequestForm::execute(Bureaucrat &src) const
{
	if (this->_signed && src.getGrade() <= this->_execute_it && src.getGrade() > 0)
	{
		std::cout << "* drilling noises  *" << std::endl;
		std::cout << this->_target << " has been robotomized successfully 50\% of the time." << std::endl;
		return 1;
	}
	std::cout << "The robotomy failed." << std::endl;
	return 0;
}
