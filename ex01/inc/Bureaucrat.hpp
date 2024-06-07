#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# include "ExceptionMaker.hpp"

class Form;

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
		void				signForm(Form &f);

		Bureaucrat operator++(int);
		Bureaucrat operator--(int);

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

		const static short	_numerical_max_grade;
		const static short	_numerical_min_grade;

	private:
		const std::string	_name;
		short				_grade;
};

std::ostream	&operator<<(std::ostream & o, Bureaucrat const & i);

#endif
