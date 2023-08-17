#include "Form.hpp"

Form::Form():m_name("default"), m_signed(false), m_grade_to_sign(50), m_grade_to_execute(40)
{
    std::cout << "Form default ctor" << std::endl;
};
Form::Form(const std::string&  name,const int grade_to_sign,const int grade_to_execute) : m_name(name), m_grade_to_sign(grade_to_sign), m_grade_to_execute(grade_to_execute)
{
    m_signed = false;
    std::cout << "Form parametr ctor" << std::endl;
}

Form::Form(const Form& obj): m_name(obj.m_name), m_signed(obj.m_signed), m_grade_to_sign(obj.m_grade_to_sign),
m_grade_to_execute(obj.m_grade_to_execute)
{
    
    std::cout << "Form copy  ctor" << std::endl;
}

Form & Form::operator=(const Form& obj)
{
    if (this != &obj)
    {
       
        m_signed = obj.m_signed;
    }  
    std::cout << "Form copy assignment operator" << std::endl;
    return (*this);
}

Form::~Form()
{
    std::cout << "Form default dctor" << std::endl;
}

std::string Form::getName(void) const
{
    return (m_name);
}

int Form::getGradeToSign(void) const
{
    return (m_grade_to_sign);
}

int Form::getGradeToExecute(void)const
{
    return(m_grade_to_execute);
}

bool        Form::isSigned() const
{
    return (m_signed);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grate too high 1");
}
const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grate too low 150");
}

std::ostream & operator << (std::ostream &op, const Form &obj)
{
	op << obj.getName()<< ", Form grade to sign " << obj.getGradeToSign()<< " and grade to execute " << obj.getGradeToExecute() << " and signed " << std::boolalpha << obj.isSigned();

	return (op);
}

void Form::beSigned( Bureaucrat& b)
{
    if (b.getGrade() <= m_grade_to_sign)
    {
        m_signed = true;
    }
    else
    {
        throw GradeTooLowException();
    }
}