#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 0, 145, 137)
{

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
		this->_signed = src._signed;
	return *this;
}

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& src)
{
	if (this->_sign_it < 1 || this->_execute_it < 1)
	{
		throw AForm::GradeTooHighException;
		return os;
	}
	else if (this->_sign_it > 150 || this->_execute_it > 150)
	{
		throw AForm::GradeTooLowException;
		return os;
	}
	os << "ShrubberyCreationForm " << this->_name << ", sign grade "
		<< this->_sign_it << ", execute grade " << this->_execute_it << " .";
	return os;
}

int	ShrubberyCreationForm::beSigned(const Bureaucrat& src)
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
	std::string		filename;
	std::ofstream	treeFile;
	int		i;
	filename = target + "_shrubbery";
	treeFile(filename);
	
	i = 0;
	while (i < 3)
	{	
		treeFile <<	           \/ |    |/ << std::endl;
		treeFile <<	        \/ / \||/  /_/___/_ << std::endl;
		treeFile <<	         \/   |/ \/ << std::endl
		treeFile <<	    _\__\_\   |  /_____/_ << std::endl;
		treeFile <<	           \  | /          / << std::endl;
		treeFile <<	  __ _-----`  |{,-----------~ << std::endl;
		treeFile <<	            \ }{ << std::endl;
		treeFile <<	             }{{ << std::endl;
		treeFile <<	             }}{ << std::endl;
		treeFile <<	             {{} << std::endl;
		treeFile <<	       , -=-~{ .-^- << std::endl;
		treeFile <<		        `} << std::endl;
		treeFile <<	              {	<< std::endl;
		treeFile << std::endl;
		i++;
	}		
	treeFile.close();
}

