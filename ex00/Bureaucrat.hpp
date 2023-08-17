#include <iostream>
#include <exception>
class Bureaucrat
{
private:
    const std::string  m_name;
    int m_grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& obj);
    Bureaucrat &operator=(const Bureaucrat& obj);
    ~Bureaucrat();
public:
    std::string getName(void) const;
    int getGrade(void) const;
    void increment();
    void decrement()  ;
    class GradeTooHighException : public std::exception 
    {
        public:
        virtual const char* what() const throw();
        
    };
    class GradeTooLowException : public std::exception 
    {
        public:
        virtual const char* what() const throw();
        
    };
};

std::ostream &operator << (std::ostream &op, const Bureaucrat &a);
