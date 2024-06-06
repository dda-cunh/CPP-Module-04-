#include "../inc/Bureaucrat.hpp"
#include <exception>

#define CLI_GREEN	"\033[32m"
#define CLI_RESET	"\033[0m"
#define CLI_CYAN	"\033[36m"

int main(void)
{
	std::cout << std::endl;
	//									Default test
	std::cout << CLI_GREEN << "------------------  Default test  ------------------";
	std::cout << CLI_RESET << std::endl << std::endl << CLI_CYAN;
	{
		Bureaucrat  _default;
		std::cout << _default << std::endl;
	}
	std::cout << CLI_RESET << std::endl;
	std::cout << CLI_GREEN << "----------------------------------------------------";
	std::cout << CLI_RESET << std::endl << std::endl;
	std::cout << CLI_GREEN << "----------------  Parametric test  -----------------";
	std::cout << CLI_RESET << std::endl << std::endl << CLI_CYAN;
	//								Parametric test
	{
		try
		{
			Bureaucrat  parametric("John", 1);
			try
			{
				parametric++;
			}
			catch (std::exception &ex)
			{
				std::cout << ex.what() << std::endl;
			}
			while (true)
			{
				try
				{
					std::cout << parametric << std::endl;
					parametric--;
				}
				catch (std::exception &ex)
				{
					std::cout << ex.what() << std::endl;
					break ;
				}
			}
		}
		catch (std::exception &ex)
		{
			std::cout << ex.what() << std::endl;
		}
	}
	std::cout << CLI_RESET << std::endl;
	std::cout << CLI_GREEN << "----------------------------------------------------";
	std::cout << CLI_RESET << std::endl << std::endl;
}
