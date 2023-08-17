#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern default ctor" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern dctor" << std::endl;
}

Intern::Intern(const Intern &)
{
    
    
}
Intern &Intern::operator=(const Intern& )
{
    return(*this);
}

AForm* Intern::makeShrubbery(const std::string &target)
{
    return(new ShrubberyCreationForm(target));
}
AForm* Intern::makeRobotomy(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidential(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm * Intern::makeForm(const std::string& nameForm, const std::string& target)
{
    std::string internMake[3] = {"Shrubbery", "Robotomy", "Presidential"};
    AForm * (Intern::*ptr_Maker[3])(const std::string & target) = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
       
    };
    for(int i = 0; i < 3; i++)
    {
        if (nameForm == internMake[i])
        {
            std::cout << "Intern creates " << nameForm << std::endl;
            return ((this->*ptr_Maker[i])(target));
        }

    }
     std::cout <<  nameForm  << "  doesn’t exist " << std::endl;
    return (NULL);
}