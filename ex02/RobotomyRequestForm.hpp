#pragma once
#include <iostream>
#include "AForm.hpp"

class  RobotomyRequestForm : public AForm
{
private:
    std::string m_target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string & target);
    RobotomyRequestForm(const RobotomyRequestForm& obj);
    RobotomyRequestForm &operator=(const RobotomyRequestForm& obj);
    ~RobotomyRequestForm();
    void action() const;
};

