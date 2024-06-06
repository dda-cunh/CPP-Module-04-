#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

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
	Form		fo("Da Form", 3, 3);

	TRY_CATCH_TEST("Valid signForm()",
		{
			Bureaucrat b("Big man", 2);
			b.signForm(fo);
		});

	TRY_CATCH_TEST("Invalid signForm() already signed",
		{
			Bureaucrat b("Big man", 4);
			b.signForm(fo);
		});

	TRY_CATCH_TEST("Invalid signForm() grade low",
		{
			Bureaucrat b("Big man", 4);
			Form f("Da Form", 3, 3);
			b.signForm(f);
		});
}
