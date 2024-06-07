#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm &operator=(PresidentialPardonForm const & rhs);
		~PresidentialPardonForm(void);

		PresidentialPardonForm(const std::string &target);

		void	execute(Bureaucrat const & executor) const;

	private:
		const std::string	_target;
};

#endif
