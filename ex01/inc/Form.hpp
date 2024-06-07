#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

# include "ExceptionMaker.hpp"

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
				GradeTooHighException();
		};

		class GradeTooLowException : public ExceptionMaker
		{
			public:
				GradeTooLowException();
		};

		class AlreadySignedException : public ExceptionMaker
		{
			public:
				AlreadySignedException();
		};
};

std::ostream	&operator<<(std::ostream & o, Form const & i);

#endif
