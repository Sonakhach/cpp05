#pragma once
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string m_name;
    bool m_signed;
    const int m_grade_to_sign;
    const int m_grade_to_execute;    
public:
    AForm();
    AForm(const std::string& name, const int grade_to_sign, const int grade_to_execute);
    AForm(const AForm& obj);
    AForm &operator=(const AForm& obj);
    virtual ~AForm();
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
public:
    void execute(Bureaucrat const & executor) const;
    virtual void action() const = 0;
};

std::ostream &operator << (std::ostream &op, const AForm &obj);
