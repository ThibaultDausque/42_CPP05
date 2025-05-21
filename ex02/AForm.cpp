#include "AForm.hpp"
#include <atomic>
#include <ostream>
#include <regex>

AForm::AForm(): _name("default"), _sign_it(42), _execute_it(42)
{
	this->_signed = 0;
}

AForm::AForm(const AForm& cpy)
{
	*this = cpy;
}

AForm::~AForm()
{

}

AForm&	AForm::operator=(const AForm& src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

std::ostream&	operator<<(std::ostream& os, AForm& src)
{
	if (src.signGrade() < 1 || src.execGrade() < 1)
	{
		throw AForm::GradeTooHighException;
		return os;
	} else if (src)
}

const std::string	AForm::getName() const
{
	return this->_name;	
}

int	AForm::execGrade() const
{
	return this->_execute_it;
}

int	AForm::signGrade() const
{
	return this->_sign_it;
}

int	AForm::beSigned(Bureaucrat &src)
{
	if (src.getGrade() <= this->_sign_it && this->signGrade() >= 1
		&& this->signGrade() <= 150)
	{
		this->_signed = 1;
		return 1;
	}
	else if (this->signGrade() < 1 || this->signGrade() > 150)
		return 2;
	return 0;
}

