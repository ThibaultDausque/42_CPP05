#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 0, 145, 137)
{
	this->_target = "toto";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy) : AForm(cpy)
{
	*this = cpy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		this->_signed = src.getSigned();
		this->_target = src.getTarget();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& src)
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
	os << "ShrubberyCreationForm " << src.getName() << ", sign grade "
		<< src.signGrade() << ", execute grade " << src.execGrade() << " .";
	return os;
}

int	ShrubberyCreationForm::beSigned(Bureaucrat& src)
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

void	ShrubberyCreationForm::asciiTrees(std::string target)
{
	std::ofstream	treeFile(target + "_shrubbery");
	int		i;
	
	i = 0;
	while (i < 3)
	{	
		treeFile <<	"           \\/ |    |/ "<< std::endl;
		treeFile <<	 "       \\/ / \\||/  /_/___/_ "<< std::endl;
		treeFile <<	 "        \\/   |/ \\/ "<< std::endl;
		treeFile <<	 "   _\\__\\_\\   |  /_____/_ "<< std::endl;
		treeFile <<	 "          \\  | /          / "<< std::endl;
		treeFile <<	 " __ _-----`  |{,-----------~ "<< std::endl;
		treeFile <<	 "           \\ }{ "<< std::endl;
		treeFile <<	 "            }{{ "<< std::endl;
		treeFile <<	 "            }}{ "<< std::endl;
		treeFile <<	 "            {{} "<< std::endl;
		treeFile <<	 "      , -=-~{ .-^- "<< std::endl;
		treeFile <<		"        `} "<< std::endl;
		treeFile <<	 "             {	"<< std::endl;
		treeFile << std::endl;
		i++;
	}		
	treeFile.close();
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}
