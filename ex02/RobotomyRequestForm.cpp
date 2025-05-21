#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robot", 0, 72, 45)
{

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
		this->_signed = src._signed;
	return *this;
}
