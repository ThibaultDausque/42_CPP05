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
		~Form();
		const std::string	getName() const;
		int	execGrade() const;
		int	signGrade() const;
 		int	beSigned(Bureaucrat &src);
		int	getSigned();

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, Form& src);

#endif
