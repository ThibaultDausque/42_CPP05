#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <ostream>

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
		int			getGrade() const;
		int			downGrade();
		int			upGrade();
		void		GradeTooHighException(int grade);
		void		GradeTooLowException(int grade);
		friend std::ostream&	operator<<(std::ostream& os, const Bureaucrat& src);
};


#endif 
