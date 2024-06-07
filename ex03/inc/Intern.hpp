#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

# include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern(void);
		Intern(Intern const & src);
		Intern &operator=(Intern const & rhs);
		~Intern(void);
	
		AForm	*makeForm(std::string form_name, std::string target)	const;

		static AForm	*makePresident(std::string target);
		static AForm	*makeShrubbery(std::string target);
		static AForm	*makeRobotomy(std::string target);

	private:
		class	UnkownFormType : public ExceptionMaker
		{
			public:
				UnkownFormType();
		};
};

#endif
