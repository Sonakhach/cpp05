#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery",145, 137)
{
    std::cout << "ShrubberyCreationForm default ctor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery",145, 137)
{
    m_target = target;
    std::cout << "ShrubberyCreationForm parameter ctor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm dctor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj): AForm("Shrubbery",145, 137)
{
    
    m_target = obj.m_target;
    std::cout << "ShrubberyCreationForm copy  ctor" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
    if (this != &obj)
    {
        AForm::operator=(obj);
        m_target = obj.m_target;
       
    }  
    std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
    return (*this);
}

void ShrubberyCreationForm::action() const
{
    std::fstream outfile(m_target + "_shrubbery", std::fstream::out);
    std::cout<< "HELLO"<<std::endl;
    if (outfile.is_open())
    {
       outfile << "          42          " << std::endl;
       outfile << "         42 42        " << std::endl;
       outfile << "      42 42 42 42     " << std::endl;
       outfile << "   42 42 42 42 42 42  " << std::endl;
       outfile << "          42          " << std::endl;
       outfile.close();
    }
    else
		std::cout << "Error in open file " << std::endl;
  
}