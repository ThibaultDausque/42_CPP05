#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm";

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& cpy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm & src);
		~RobotomyRequestForm();
		void	informs(const std::string &target);
};

#endif
