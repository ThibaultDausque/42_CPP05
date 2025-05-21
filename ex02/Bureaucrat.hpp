#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <ostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& cpy);
		Bureaucrat& operator=(const Bureaucrat& src);
		~Bureaucrat();
		const std::string	getName() const;
		int		getGrade() const;
		int		downGrade();
		int		upGrade();
		int		signForm(AForm &src);
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what() const throw()
			{
				return "* grade too high *";
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what() const throw()
			{
				return "* grade too low *";
			}
	};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& src);

#endif 
