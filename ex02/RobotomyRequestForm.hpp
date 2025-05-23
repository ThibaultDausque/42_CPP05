#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& cpy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm & src);
		~RobotomyRequestForm();
		int	execute(Bureaucrat &src) const;
		std::string getTarget() const;
};

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& src);

#endif
