#include "../inc/Bureaucrat.hpp"
#include <string>

//--------------------------  CANONICAL  --------------------------//
Bureaucrat::Bureaucrat(void) : _name("Default Bureaucrat"), _grade(150)
{
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	// std::cout << "Copy Assignement operator called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}
//-----------------------------------------------------------------//

//-------------------------  CONSTRUCTORS  ------------------------//
Bureaucrat::Bureaucrat(std::string name, short grade)	throw()
	: _name(name)
{
	if (grade < _min_grade)
		throw (Bureaucrat::GradeTooHighException());
	
}
//-----------------------------------------------------------------//

//-----------------------  MEMBER FUNCTIONS  ----------------------//

const short	&Bureaucrat::getGrade()	const
{
	return (this->_grade);
}

const std::string	&Bureaucrat::getName()	const
{
	return (this->_name);
}
//-----------------------------------------------------------------//

//------------------------  STATIC MEMBERS  -----------------------//
const short Bureaucrat::_max_grade = 150;
const short Bureaucrat::_min_grade = 1;
//-----------------------------------------------------------------//


