#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():m_name("default"), m_grade(100)
{
    std::cout << "default ctor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "default dctor" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string&  name, int grade) : m_name(name)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw  GradeTooHighException();
    else
        m_grade = grade;
    std::cout << "parametr ctor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj): m_name(obj.m_name)
{
        this->m_grade = obj.m_grade;
    std::cout << "copy  ctor" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat& obj)
{
    if (this != &obj)
    {
       
        m_grade = obj.m_grade;
    }  
    std::cout << "copy assignment operator" << std::endl;
    return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grate too high 1");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grate too low 150");
}


std::string Bureaucrat::getName(void) const
{
    return (m_name);
}

int Bureaucrat::getGrade(void) const
{
    return (m_grade);
}

void Bureaucrat::increment()
{
    if (m_grade <= 1)
        throw GradeTooHighException();
    --m_grade;

}
void Bureaucrat::decrement()
{
    if (m_grade >= 150)
        throw GradeTooLowException();
    ++m_grade;

}

std::ostream & operator << (std::ostream &op, const Bureaucrat &obj)
{
	op << obj.getName()<< ", bureaucrat grade " << obj.getGrade();
	return (op);
}

void Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName()  << " signed " << form.getName() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn’t sign "<< form.getName() << " because " << e.what() << std::endl;
    }
    
}
void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName()  << " executed " << form.getName() << std::endl;   
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't execut " << form.getName() << " because "<< e.what() << '\n';
    }
    
    
}