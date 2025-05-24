#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& cpy)
{
	*this = cpy;
}

Intern::~Intern()
{

}

Intern&	Intern::operator=(const Intern& src)
{
	(void) src;
	return *this;
}

AForm	*Intern::makePresident(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobot(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	AForm* (*tab[3])(std::string) = { &makePresident, &makeRobot, &makeShrubbery };
	std::string	form[3] = { "PresidentialPardonForm", "RobotRequestForm", "ShrubberyCreationForm" };

	for (int i = 0; i < 3; i++)
	{
		if (form[i] == form_name)
		{
			std::cout << "Intern creates " << form[i] << std::endl;
			return tab[i](target);
		}
	}
	std::cout << "Error: form name not found." << std::endl;
	return NULL;
}
