#include "RobotomyRequestForm.hpp"

RobotomyRequestForm:: RobotomyRequestForm(): AForm("Robotomy", 72, 45)
{
    m_target = "Robotomy";
    std::cout << "RobotomyRequestForm default ctor" << std::endl;
}

RobotomyRequestForm:: RobotomyRequestForm(const std::string & target): AForm("Robotomy", 72, 45)
{
    m_target = target;
    std::cout << "RobotomyRequestForm parametr ctor" << std::endl;
}

RobotomyRequestForm::~ RobotomyRequestForm()
{
     std::cout << "RobotomyRequestForm dctor" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj): AForm("Robotomy", 72, 45)
{
    m_target = obj.m_target;
    std::cout << "RobotomyRequestForm copy  ctor" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
    if (this != &obj)
    {
       AForm::operator=(obj);
       m_target = obj.m_target;
       
    }  
    std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
    return (*this);
}

 void RobotomyRequestForm::action() const
 {
    std::srand(time(NULL));
    int randNum = std::rand() % 2;
    switch(randNum) {
        case 0 :
            std::cout << m_target << " has been robotomized successfully 50% of the time" << std::endl;
            break ;
        default:
            std::cout << m_target << "'s robotomy failed" << std::endl;
    }
        
 }