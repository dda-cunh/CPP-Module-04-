#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
#include <string>

# ifndef EXCEPTION_MAKER_CLASS
#  define EXCEPTION_MAKER_CLASS
class ExceptionMaker : public std::exception
{
	public:
		~ExceptionMaker()	throw()
		{}

		ExceptionMaker(const std::string message)
			: _message(message)
		{}

		const char* what()	const	throw()
		{
			return (this->_message.c_str());
		}

	protected:
		std::string	_message;
};
# endif

class	Bureaucrat;

class	Form
{
	public:
		Form(void);
		Form(Form const & src);
		Form &operator=(Form const & rhs);
		~Form(void);

		Form(std::string name, short req_sign_grade, short req_exec_grade);

		void	beSigned(const Bureaucrat& b);

		const std::string	&getName()			const;
		const short			&getReqSignGrade()	const;
		const short			&getReqExecGrade()	const;
		const bool			&getSigned()		const;

	private:
		const std::string	_name;
		const short			_numerical_required_sign_grade;
		const short			_numerical_required_exec_grade;
		bool				_signed;

		class GradeTooHighException : public ExceptionMaker
		{
			public:
				GradeTooHighException()
					: ExceptionMaker("Grade goes beyond the best possible grade")
				{}
		};

		class GradeTooLowException : public ExceptionMaker
		{
			public:
				GradeTooLowException()
					: ExceptionMaker("Grade goes beyond the worst possible grade")
				{}
		};

		class AlreadySignedException : public ExceptionMaker
		{
			public:
				AlreadySignedException()
					: ExceptionMaker("The form is already signed")
				{}
		};
};

std::ostream	&operator<<(std::ostream & o, Form const & i);

#endif
