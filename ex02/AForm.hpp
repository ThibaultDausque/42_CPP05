#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <ostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		bool	_signed;
		const int	_sign_it;
		const int	_execute_it;
	
	public:
		AForm();
		AForm(const std::string _name, bool _signed, const int _sign_it, const int _execute_it);
		AForm(const AForm& cpy);
		AForm&	operator=(const AForm& src);
		virtual ~AForm();
		const std::string	getName() const;
		int	execGrade() const;
		int	signGrade() const;
 		int	beSigned(Bureaucrat &src);
		virtual int execute(Bureaucrat &src) const = 0;
		int	getSigned() const;
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

std::ostream&	operator<<(std::ostream& os, AForm& src);

#endif
