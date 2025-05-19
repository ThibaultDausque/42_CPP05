#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <ostream>
# include <exception>

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
		int		signForm(Form& src);
	class gradeTooHighException : public std::exception
	{
		public:
			virtual const char*	what() const throw()
			{
				return "* grade too high *";
			}
	};
	class gradeTooLowException : public std::exception
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
