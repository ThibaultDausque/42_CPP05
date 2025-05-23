#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 0, 25, 5)
{
	this->_target = "tata";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy) : AForm(cpy)
{
	*this = cpy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
		this->_signed = src._signed;
	return *this;
}

std::ostream&	operator<<(std::ostream& os, PresidentialPardonForm& src)
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
	os << "PresidentialPardonForm sign grade " << src.signGrade() << ", exec grade " << src.execGrade() << ".";
	return os;
}

int	PresidentialPardonForm::execute(Bureaucrat &src) const
{
	if (this->_signed && src.execGrade() <= this->_execute_it)
	{
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		return 1;
	}
	return 0;
}
