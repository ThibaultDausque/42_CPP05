#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <ostream>
# include <stdexcept>

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
		void		GradeTooHighException(int grade);
		void		GradeTooLowException(int grade);
		
};

std::ostream&	operator<<(std::ostream& os, const Form& src);

#endif
