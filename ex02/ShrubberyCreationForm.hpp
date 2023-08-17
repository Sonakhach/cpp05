
#pragma once
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string m_target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm& obj);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm& obj);
    ~ShrubberyCreationForm();
public:
    void action() const;
    
};


