#include "Form.hpp"

Form::Form(): _name("death_note"), _sign_it(42), _execute_it(42)
{
	this->_signed = 0;
}

Form::Form(const Form& cpy)
{
	*this->cpy;
}

Form::~Form()
{

}

Form&	Form::operator=(const Form& src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

int	Form::beSigned(Bureaucrat& src)
{
	if (src.getGrade() < this->_sign_it)
	{
		throw Form::GradeTooHighException();
		return 0;
	} else if (src.getGrade() > this->_sign_it)
	{
		throw Form::GradeTooLowException;
		return 0;
	}
	return this->_signed = 1;
}

const int	Form::execGrade()
{
	return this->_execute_it;
}

const int Form::signGrade()
{
	return this->_sign_it;
}
