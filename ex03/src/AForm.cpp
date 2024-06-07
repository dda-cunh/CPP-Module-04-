#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

//-------------------------------  CANONICAL  -------------------------------//
AForm::AForm(void) : _name("Default AForm"), _numerical_required_sign_grade(1),
	_numerical_required_exec_grade(1), _signed(false)
{
	// std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(AForm const & src) : _name(src._name),
	_numerical_required_sign_grade(src._numerical_required_sign_grade),
	_numerical_required_exec_grade(src._numerical_required_exec_grade)
{
	// std::cout << "Copy constructor called" << std::endl;
	if (src._numerical_required_exec_grade < Bureaucrat::_numerical_min_grade
		|| src._numerical_required_sign_grade < Bureaucrat::_numerical_min_grade)
		throw (AForm::GradeTooHighException());
	if (src._numerical_required_exec_grade > Bureaucrat::_numerical_max_grade
		|| src._numerical_required_sign_grade > Bureaucrat::_numerical_max_grade)
		throw (AForm::GradeTooLowException());
	*this = src;
}

AForm & AForm::operator=(AForm const & rhs)
{
	// std::cout << "Copy Assignement operator called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

AForm::~AForm(void)
{
	// std::cout << "Destructor called" << std::endl;
}
//---------------------------------------------------------------------------//

//-----------------------------  CONSTRUCTORS  ------------------------------//
AForm::AForm(std::string name, short req_sign_grade, short req_exec_grade) :
	_name(name),
	_numerical_required_sign_grade(req_sign_grade),
	_numerical_required_exec_grade(req_exec_grade),
	_signed(false)
{
	if (req_exec_grade < Bureaucrat::_numerical_min_grade
		|| req_sign_grade < Bureaucrat::_numerical_min_grade)
		throw (AForm::GradeTooHighException());
	if (req_exec_grade > Bureaucrat::_numerical_max_grade
		|| req_sign_grade > Bureaucrat::_numerical_max_grade)
		throw (AForm::GradeTooLowException());
}
//---------------------------------------------------------------------------//

//---------------------------   MEMBER FUNCTIONS  ---------------------------//
void	AForm::beSigned(const Bureaucrat& b)
{
	short	grade;

	if (this->_signed)
		throw (AForm::AlreadySignedException());
	grade = b.getGrade();
	if (grade > this->_numerical_required_sign_grade)
		throw (AForm::GradeTooLowException());
	this->_signed = true;
}

const std::string	&AForm::getName()	const
{
	return (this->_name);
}

const short	&AForm::getReqSignGrade()	const
{
	return (this->_numerical_required_sign_grade);
}

const short	&AForm::getReqExecGrade()	const
{
	return (this->_numerical_required_exec_grade);
}

const bool	&AForm::getSigned()	const
{
	return (this->_signed);
}

void	AForm::executeValidator(Bureaucrat const &executor)	const
{
	if (!this->_signed)
		throw (AForm::NotSignedException());
	if (executor.getGrade() > this->_numerical_required_exec_grade)
		throw (AForm::GradeTooLowException());
}

//---------------------------------------------------------------------------//

//------------------------------  EXCEPTIONS  -------------------------------//
AForm::GradeTooHighException::GradeTooHighException()
	: ExceptionMaker("Grade goes beyond the best possible grade")
{

}

AForm::GradeTooLowException::GradeTooLowException()
	: ExceptionMaker("Grade goes beyond the worst possible grade")
{

}

AForm::AlreadySignedException::AlreadySignedException()
	: ExceptionMaker("The Form is already signed")
{

}

AForm::NotSignedException::NotSignedException()
	: ExceptionMaker("The Form isn't signed")
{

}
//---------------------------------------------------------------------------//

//--------------------------  NON MEMBER FUNCTIONS  -------------------------//
std::ostream	&operator<<(std::ostream & o, AForm const & i)
{
	o << i.getName() << ", sign grade ";
	o <<  i.getReqSignGrade() << ", execute grade ";
	o << i.getReqExecGrade() << (!i.getSigned() ? ", not " : ", " ) << "signed";
	return (o);
}
//---------------------------------------------------------------------------//
