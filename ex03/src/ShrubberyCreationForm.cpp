#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>

//--------------------------------  CANONICAL  --------------------------------//
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm default", 145, 137)
{
	// std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
: AForm(src.getName(), src.getReqSignGrade(), src.getReqExecGrade())
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	// std::cout << "Copy Assignement operator called" << std::endl;
	(void) rhs;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << "Destructor called" << std::endl;
}
//-----------------------------------------------------------------------------//

//-------------------------------  CONSTRUCTORS  ------------------------------//
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}
//-----------------------------------------------------------------------------//

//-----------------------------  MEMBER FUNCTIONS  ----------------------------//
void	ShrubberyCreationForm::execute(Bureaucrat const &executor)	const
{
	try
	{
		ShrubberyCreationForm::AForm::executeValidator(executor);
		std::ofstream	out((this->_target + "_shrubbery").c_str());

		if (out.is_open())
		{
			out << "                                              ." << std::endl;
			out << "                                   .         ;" << std::endl;
			out << "      .              .              ;%     ;;" << std::endl;
			out << "        ,           ,                :;%  %;" << std::endl;
			out << "         :         ;                   :;%;'" << std::endl;
			out << ",.        %;     %;            ;        %;'    ,;" << std::endl;
			out << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
			out << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
			out << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
			out << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
			out << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
			out << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
			out << "           `@%:.  :;%.         ;@@%;'" << std::endl;
			out << "             `@%.  `;@%.      ;@@%;" << std::endl;
			out << "               `@%%. `@%%    ;@@%;" << std::endl;
			out << "                 ;@%. :@%%  %@@%;" << std::endl;
			out << "                   %@bd%%%bd%%:;" << std::endl;
			out << "                     #@%%%%%:;;" << std::endl;
			out << "                     %@@%%%::;" << std::endl;
			out << "                     %@@@%(o);  . '" << std::endl;
			out << "                     %@@@o%;:(.,'" << std::endl;
			out << "                 `.. %@@@o%::;" << std::endl;
			out << "                    `)@@@o%::;" << std::endl;
			out << "                     %@@(o)::;" << std::endl;
			out << "                    .%@@@@%::;" << std::endl;
			out << "                    ;%@@@@%::;." << std::endl;
			out << "                   ;%@@@@%%:;;;." << std::endl;
			out << "uwu            ...;%@@@@@%%:;;;;,.." << std::endl;
			out.close();
		}
	}
	catch (AForm::NotSignedException const &ex)
	{
		throw(ex);
	}
	catch (AForm::GradeTooLowException const &ex)
	{
		throw(ex);
	}
}
//-----------------------------------------------------------------------------//

//-----------------------------  STATIC MEMBERS  ----------------------------//
const char	ShrubberyCreationForm::form_type[4] = "SCF";
//---------------------------------------------------------------------------//
