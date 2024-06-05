#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <string>

class CustomException : public std::exception
{
	public:
		virtual ~CustomException() = 0;

		CustomException(const std::string message)
			: _message(message){}

		const char* what()	const throw()
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
		Bureaucrat & operator=(Bureaucrat const & rhs);
		~Bureaucrat(void);

		Bureaucrat(std::string name, short grade)	throw();

		const std::string	&getName()	const;
		const short			&getGrade()	const;

	private:
		const std::string	_name;
		short				_grade;

		class GradeTooHighException : public CustomException
		{
			public:
				GradeTooHighException(std::string message)
					: CustomException(message){}
		};

		class GradeTooLowException : public CustomException
		{
			public:
				GradeTooLowException(std::string message)
					: CustomException(message){}
		};

		const static short					_max_grade;
		const static short					_min_grade;
};

#endif