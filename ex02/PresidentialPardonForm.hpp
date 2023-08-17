#pragma once
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
    std::string m_target;
public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& obj);
    PresidentialPardonForm &operator=(const PresidentialPardonForm& obj);
    ~PresidentialPardonForm();
    void action() const;
};

