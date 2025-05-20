#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <ostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool	_signed;
		const int	_sign_it;
		const int	_execute_it;
	public:
		Form();
		Form(const Form& cpy);
		Form&	operator=(const Form& src);
		virtual ~Form();
		const std::string	getName() const;
		virtual int	execGrade() const = 0;
		virtual int	signGrade() const;
 		int	beSigned(Bureaucrat &src);
		int	getSigned();

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what() const throw()
			{
				return "* grade too high to sign *";
			}
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what() const throw()
			{
				return "* grade too low to sign *";
			}
	};
};

std::ostream&	operator<<(std::ostream& os, Form& src);

#endif
