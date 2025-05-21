#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();
		void	asciiTrees(std::string target);
		int	beSigned(const Bureaucrat& src);
};

std::ostream& operator<<(std::ostream& os, ShrubberyCreationForm& src);

#endif
