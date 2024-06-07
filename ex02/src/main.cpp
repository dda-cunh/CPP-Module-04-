#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"

#define CLI_GREEN		"\033[32m"
#define CLI_RESET		"\033[0m"
#define CLI_CYAN		"\033[36m"

#define TEST_LINE_LEN	100

#define TRY_CATCH_TEST(name, test_scope)			\
	do												\
	{												\
		testHeader(std::cout, name);				\
		try											\
			test_scope								\
		catch (std::exception &ex)					\
		{											\
			std::cout << ex.what() << std::endl;	\
		}											\
		testFooter(std::cout);						\
	} while(0)

void	testFooter(std::ostream &o)
{
	o << std::endl << CLI_GREEN;
	o << std::string(TEST_LINE_LEN, '-');
	o << CLI_RESET << std::endl;
}

void	testHeader(std::ostream &o, std::string name)
{
	size_t		len;

	testFooter(std::cout);
	if (name.length() > TEST_LINE_LEN / 2)
		name = "  " + name.substr(TEST_LINE_LEN / 2) + " test  ";
	else
		name = "  " + name + " test  ";
	o << std::endl << CLI_GREEN;
	len = (TEST_LINE_LEN / 2) - (name.length() / 2);
	o << std::string(len, '-') << name;
	if (name.length() & 1)
		len--;
	o << std::string(len, '-') << std::endl << std::endl << CLI_CYAN;
}

int main(void)
{
	Bureaucrat	op("Genghis Khan", 1);

	TRY_CATCH_TEST("ShrubberyCreationForm",
		{
			ShrubberyCreationForm	shrub("ShrubberyCreation");
			op.signAForm(shrub);
			op.executeForm(shrub);
		});
	TRY_CATCH_TEST("RobotomyRequestForm",
		{
			RobotomyRequestForm		rob("Robotomy");
			op.signAForm(rob);
			op.executeForm(rob);
		});
	TRY_CATCH_TEST("PresidentialPardonForm",
		{
			PresidentialPardonForm	pres("PresidentialPardon");
			op.signAForm(pres);
			op.executeForm(pres);
		});
	TRY_CATCH_TEST("Low-Tier Bureaucrat",
		{
			PresidentialPardonForm	pres("Tom Foolery");
			Bureaucrat				l("Trump", 150);

			l.signAForm(pres);
			l.executeForm(pres);
		});
}
