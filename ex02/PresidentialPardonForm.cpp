#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string & target):AForm("Presidential", 25, 5)
{
    m_target = target;
    std::cout << "PresidentialPardonForm parametr ctor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm dctor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj):AForm("Presidential", 25, 5)
{
    m_target = obj.m_target;
    std::cout << "PresidentialPardonForm copy  ctor" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
    if (this != &obj)
    {
       AForm::operator=(obj);
       m_target = obj.m_target;
       
    }  
    std::cout << "PresidentialPardonForm copy assignment operator" << std::endl;
    return (*this);
}

void PresidentialPardonForm::action() const
{
    std::cout << m_target << " has been pardoned by Zaphod Beeblebrox " << std::endl;
}