#include "../inc/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

//--------------------------------  CANONICAL  --------------------------------//
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm default", 72, 45)
{
	// std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
: AForm(src.getName(), src.getReqSignGrade(), src.getReqExecGrade())
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	// std::cout << "Copy Assignement operator called" << std::endl;
	(void) rhs;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// std::cout << "Destructor called" << std::endl;
}
//-----------------------------------------------------------------------------//

//-------------------------------  CONSTRUCTORS  ------------------------------//
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{}
//-----------------------------------------------------------------------------//

//-----------------------------  MEMBER FUNCTIONS  ----------------------------//
void	RobotomyRequestForm::execute(Bureaucrat const &executor)	const
{
	try
	{
		RobotomyRequestForm::AForm::executeValidator(executor);
		std::srand(std::time(NULL));
        bool    robotomized = rand() % 2;
        if (robotomized)
            std::cout << this->_target << " has been robotomized" << std::endl;
        else
            std::cout << this->_target << " robotomy failed" << std::endl;
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

//-----------------------------  STATIC MEMBERS  ----------------------------//
const char	RobotomyRequestForm::form_type[4] = "RRF";
//---------------------------------------------------------------------------//