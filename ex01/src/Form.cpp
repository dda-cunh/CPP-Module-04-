#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

//-------------------------------  CANONICAL  -------------------------------//
Form::Form(void) : _name("Default Form"), _numerical_required_sign_grade(1),
	_numerical_required_exec_grade(1), _signed(false)
{
	// std::cout << "Default constructor called" << std::endl;
}

Form::Form(Form const & src) : _name(src._name),
	_numerical_required_sign_grade(src._numerical_required_sign_grade),
	_numerical_required_exec_grade(src._numerical_required_exec_grade)
{
	// std::cout << "Copy constructor called" << std::endl;
	if (src._numerical_required_exec_grade < Bureaucrat::_numerical_min_grade
		|| src._numerical_required_sign_grade < Bureaucrat::_numerical_min_grade)
		throw (Form::GradeTooHighException());
	if (src._numerical_required_exec_grade > Bureaucrat::_numerical_max_grade
		|| src._numerical_required_sign_grade > Bureaucrat::_numerical_max_grade)
		throw (Form::GradeTooLowException());
	*this = src;
}

Form & Form::operator=(Form const & rhs)
{
	// std::cout << "Copy Assignement operator called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

Form::~Form(void)
{
	// std::cout << "Destructor called" << std::endl;
}
//---------------------------------------------------------------------------//

//-----------------------------  CONSTRUCTORS  ------------------------------//
Form::Form(std::string name, short req_sign_grade, short req_exec_grade) :
	_name(name),
	_numerical_required_sign_grade(req_sign_grade),
	_numerical_required_exec_grade(req_exec_grade),
	_signed(false)
{
	if (req_exec_grade < Bureaucrat::_numerical_min_grade
		|| req_sign_grade < Bureaucrat::_numerical_min_grade)
		throw (Form::GradeTooHighException());
	if (req_exec_grade > Bureaucrat::_numerical_max_grade
		|| req_sign_grade > Bureaucrat::_numerical_max_grade)
		throw (Form::GradeTooLowException());
}
//---------------------------------------------------------------------------//

//---------------------------   MEMBER FUNCTIONS  ---------------------------//
void	Form::beSigned(const Bureaucrat& b)
{
	short	grade;

	if (this->_signed)
		throw (Form::AlreadySignedException());
	grade = b.getGrade();
	if (grade > this->_numerical_required_sign_grade)
		throw (Form::GradeTooLowException());
	this->_signed = true;
}

const std::string	&Form::getName()	const
{
	return (this->_name);
}

const short	&Form::getReqSignGrade()	const
{
	return (this->_numerical_required_sign_grade);
}

const short	&Form::getReqExecGrade()	const
{
	return (this->_numerical_required_exec_grade);
}

const bool	&Form::getSigned()	const
{
	return (this->_signed);
}

//---------------------------------------------------------------------------//

//--------------------------  NON MEMBER FUNCTIONS  -------------------------//
std::ostream	&operator<<(std::ostream & o, Form const & i)
{
	o << i.getName() << ", sign grade ";
	o <<  i.getReqSignGrade() << ", execute grade ";
	o << i.getReqExecGrade() << (!i.getSigned() ? ", not " : ", " ) << "signed";
	return (o);
}
//---------------------------------------------------------------------------//