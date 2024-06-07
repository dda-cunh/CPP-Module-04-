#ifndef AForm_HPP
# define AForm_HPP

# include <string>

# include "ExceptionMaker.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm(void);
		AForm(AForm const & src);
		AForm &operator=(AForm const & rhs);
		virtual ~AForm(void) = 0;

		AForm(std::string name, short req_sign_grade, short req_exec_grade);

		virtual void	execute(Bureaucrat const & executor)				const = 0;

		const std::string	&getName()										const;
		const short			&getReqSignGrade()								const;
		const short			&getReqExecGrade()								const;
		const bool			&getSigned()									const;
		void				executeValidator(Bureaucrat const & executor)	const; 
		void				beSigned(const Bureaucrat& b);

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
		class NotSignedException : public ExceptionMaker
		{
			public:
				NotSignedException();
		};

	private:
		const std::string	_name;
		const short			_numerical_required_sign_grade;
		const short			_numerical_required_exec_grade;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream & o, AForm const & i);

#endif
