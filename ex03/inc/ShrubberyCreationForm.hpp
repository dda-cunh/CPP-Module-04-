#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const & rhs);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm(const std::string &target);

		void	execute(Bureaucrat const & executor) const;

		static const char	form_type[4];

	private:
		const std::string	_target;
};

#endif
