#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm &operator=(RobotomyRequestForm const & rhs);
		~RobotomyRequestForm(void);

		RobotomyRequestForm(const std::string &target);

		void	execute(Bureaucrat const & executor) const;

	private:
		const std::string	_target;
};

#endif
