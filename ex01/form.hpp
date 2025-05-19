#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <ostream>
# include <exception>

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
		const int	execGrade() const;
		const int	signGrade() const;
		int	beSigned(Bureaucrat& src);
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

std::ostream&	operator<<(std::ostream& os, const Form& src);

#endif
