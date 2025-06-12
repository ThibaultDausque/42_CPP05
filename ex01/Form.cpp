#include "Form.hpp"

Form::Form(): _name("paper"), _sign_it(43), _execute_it(42)
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
	if (src.signGrade() < 1 || src.execGrade() < 1)
	{
		throw Form::GradeTooHighException();
		return os;
	}
	else if (src.signGrade() > 150 || src.execGrade() > 150)
	{
		throw Form::GradeTooLowException();
		return os;
	}
	os << "Form " << src.getName() << " exec grade " << src.execGrade()
		<< ", sign grade " << src.signGrade();
	return os;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "* form grade too high *";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "* form grade too low *";
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

int	Form::execGrade() const
{
	return this->_execute_it;
}

int	Form::signGrade() const
{
	return this->_sign_it;
}

