#include "Form.hpp"

Form::Form(): _name("paper"), _sign_it(42), _execute_it(42)
{
	this->_signed = 0;
}

Form::Form(const Form& cpy): _name("paper"), _sign_it(42), _execute_it(42)
{
	*this = cpy;
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

std::ostream&	operator<<(std::ostream& os, Form& src)
{
	if (src.getSigned() == 1)
		os << "He signed the " << src.getName() << " form.";
	return os;
}

const std::string	Form::getName() const
{
	return this->_name;
}

int	Form::getSigned()
{
	return this->_signed;
}

int	Form::beSigned(Bureaucrat &src)
{
	if (src.getGrade() < this->_sign_it || src.getGrade() < this->_execute_it)
	{
		throw Form::GradeTooHighException();
		return 0;
	}
	else if (src.getGrade() > this->_sign_it || src.getGrade() > this->_execute_it)
	{
		throw Form::GradeTooLowException();
		return 0;
	}
	this->_signed = 1;
	return 0;
}

int	Form::execGrade() const
{
	return this->_execute_it;
}

int	Form::signGrade() const
{
	return this->_sign_it;
}



