#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
   
    
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("Shrubbery", "Bender");
    delete rrf;
    
    return 0;
}