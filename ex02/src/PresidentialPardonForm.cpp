#include "../inc/PresidentialPardonForm.hpp"

//--------------------------------  CANONICAL  --------------------------------//
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm default", 25, 5)
{
	// std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
: AForm(src.getName(), src.getReqSignGrade(), src.getReqExecGrade())
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	// std::cout << "Copy Assignement operator called" << std::endl;
	(void) rhs;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// std::cout << "Destructor called" << std::endl;
}
//-----------------------------------------------------------------------------//

//-------------------------------  CONSTRUCTORS  ------------------------------//
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{}
//-----------------------------------------------------------------------------//

//-----------------------------  MEMBER FUNCTIONS  ----------------------------//
void	PresidentialPardonForm::execute(Bureaucrat const &executor)	const
{
	try
	{
		PresidentialPardonForm::AForm::executeValidator(executor);
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.";
		std::cout << std::endl;
	}
	catch (AForm::NotSignedException const &ex)
	{
		throw(ex);
	}
	catch (AForm::GradeTooLowException const &ex)
	{
		throw(ex);
	}
}
//-----------------------------------------------------------------------------//
