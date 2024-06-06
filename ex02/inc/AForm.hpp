#ifndef AForm_HPP
# define AForm_HPP

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
					: ExceptionMaker("The Form is already signed")
				{}
		};
		class NotSignedException : public ExceptionMaker
		{
			public:
				NotSignedException()
					: ExceptionMaker("The Form isn't signed")
				{}
		};

	private:
		const std::string	_name;
		const short			_numerical_required_sign_grade;
		const short			_numerical_required_exec_grade;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream & o, AForm const & i);

#endif
