#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

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

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat &operator=(Bureaucrat const & rhs);
		~Bureaucrat(void);

		Bureaucrat(std::string name, short grade);

		const std::string	&getName()	const;
		const short			&getGrade()	const;

		Bureaucrat operator++(int);
		Bureaucrat operator--(int);

	private:
		const std::string	_name;
		short				_grade;

		const static short	_numerical_max_grade;
		const static short	_numerical_min_grade;

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
};

std::ostream	&operator<<(std::ostream & o, Bureaucrat const & i);

#endif
