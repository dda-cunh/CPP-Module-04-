#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

//-------------------------------  CANONICAL  -------------------------------//
Intern::Intern(void)
{
	// std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(Intern const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Intern & Intern::operator=(Intern const & rhs)
{
	// std::cout << "Copy Assignement operator called" << std::endl;
	(void) rhs;
	return (*this);
}

Intern::~Intern(void)
{
	// std::cout << "Destructor called" << std::endl;
}
//---------------------------------------------------------------------------//

//----------------------------  MEMBER FUNCTIONS  ---------------------------//
AForm	*Intern::makeForm(std::string form_name, std::string target)	const
{
	static AForm * (*formMakingFunctions[])(std::string) =
		{
			Intern::makeShrubbery,
			Intern::makeRobotomy,
			Intern::makePresident
		};
	static std::string	form_types[] =
		{
			ShrubberyCreationForm::form_type,
			RobotomyRequestForm::form_type,
			PresidentialPardonForm::form_type
		};

	for (int i = 0; i < 4; i++)
		if (form_name == form_types[i])
			return (formMakingFunctions[i](target));
	throw (Intern::UnkownFormType());
}
//---------------------------------------------------------------------------//

//------------------------------  EXCEPTIONS  -------------------------------//
Intern::UnkownFormType::UnkownFormType()
: ExceptionMaker("Form type is unknown")
{

}
//---------------------------------------------------------------------------//

//-----------------------------  STATIC MEMBERS  ----------------------------//
AForm	*Intern::makePresident(std::string target)
{
	std::cout << "Intern creates PresidentialPardonForm" << std::endl;
	return (new PresidentialPardonForm(target));
}
AForm	*Intern::makeShrubbery(std::string target)
{
	std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
	return (new ShrubberyCreationForm(target));
}
AForm	*Intern::makeRobotomy(std::string target)
{
	std::cout << "Intern creates RobotomyRequestForm" << std::endl;
	return (new RobotomyRequestForm(target));
}
//---------------------------------------------------------------------------//