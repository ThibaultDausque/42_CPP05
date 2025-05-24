#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 0, 145, 137)
{
	this->_target = "toto";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 0, 145, 137)
{
	this->_target = target;
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
		<< src.signGrade() << ", execute grade " << src.execGrade() << ".";
	return os;
}

int	ShrubberyCreationForm::execute(Bureaucrat &src) const
{
	std::ofstream	treeFile;
	int		i;
	
	if (this->_signed && src.getGrade() <= this->_execute_it && src.getGrade() > 0)
	{
		treeFile.open((this->_target + "_shrubbery").c_str());
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
		return 1;
	}
	return 0;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}
