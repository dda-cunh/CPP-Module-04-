#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <exception>

//--------------------------  CANONICAL  --------------------------//
Bureaucrat::Bureaucrat(void) : _name("Default Bureaucrat"), _grade(150)
{
	// std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
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
}
//-----------------------------------------------------------------//

//-------------------------  CONSTRUCTORS  ------------------------//
Bureaucrat::Bureaucrat(std::string name, short grade)
	: _name(name)
{
	if (grade < _numerical_min_grade)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > _numerical_max_grade)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
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

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat	copy(*this);

	if (this->_grade - 1 >= Bureaucrat::_numerical_min_grade)
		this->_grade--;
	else
		throw (Bureaucrat::GradeTooHighException());
	return (copy);
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << *this << " signed " << f << std::endl;
	}
	catch (std::exception &ex)
	{
		std::cout << *this << " couldn't sign " << f << ". Because ";
		std::cout << ex.what() << std::endl;
	}
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat	copy(*this);

	if (this->_grade + 1 <= Bureaucrat::_numerical_max_grade)
		this->_grade++;
	else
		throw (Bureaucrat::GradeTooLowException());
	return (copy);
}
//-----------------------------------------------------------------//

//------------------------  STATIC MEMBERS  -----------------------//
const short Bureaucrat::_numerical_max_grade = 150;
const short Bureaucrat::_numerical_min_grade = 1;
//-----------------------------------------------------------------//

//---------------------  NON MEMBER FUNCTIONS  --------------------//
std::ostream	&operator<<(std::ostream & o, Bureaucrat const & i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return (o);
}
//-----------------------------------------------------------------//

