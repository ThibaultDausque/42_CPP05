#include "AForm.hpp"

AForm::AForm(): _name("default"), _sign_it(42), _execute_it(42)
{
	this->_signed = 0;
}

AForm::AForm(const AForm& cpy): _name("default"), _sign_it(42), _execute_it(42)
{
	*this = cpy;
}

AForm::AForm(const std::string _name, bool _signed, const int _sign_it, const int _execute_it):
	_name(_name), _sign_it(_sign_it), _execute_it(_execute_it)
{
	this->_signed = _signed;
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
		throw AForm::GradeTooHighException();
		return os;
	}
	else if (src.signGrade() > 150 || src.execGrade() > 150)
	{
		throw AForm::GradeTooLowException();
		return os;
	}
	os << "Form " << src.getName() << ", sign grade " << src.signGrade()
		<< ", exec grade " << src.execGrade();
	return os;
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

int	AForm::execute(Bureaucrat &src) const
{
	if (this->_signed && src.getGrade() > 1 && src.getGrade() < 150)
		return 1;
	return 0;
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

int	AForm::getSigned() const
{
	return this->_signed;
}
