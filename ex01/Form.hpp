#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string m_name;
    bool       m_signed;
    const int m_grade_to_sign;
    const int m_grade_to_execute;    
public:
    Form();
    Form(const std::string& name, const int grade_to_sign, const int grade_to_execute);
    Form(const Form& obj);
    Form &operator=(const Form& obj);
    ~Form();
public:
    void beSigned( Bureaucrat& b);
    std::string getName(void) const;
    int getGradeToSign(void)const;
    int getGradeToExecute(void)const;
    bool        isSigned() const;
    class GradeTooHighException: public std::exception
    {
        public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException: public std::exception 
    {
        public:
        virtual const char* what() const throw();
        
    };
};

std::ostream &operator << (std::ostream &op, const Form &obj);
