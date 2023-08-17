#include "AForm.hpp"

AForm::AForm():m_name("default"), m_signed(false), m_grade_to_sign(50), m_grade_to_execute(40)
{
    std::cout << "AForm default ctor" << std::endl;
};
AForm::AForm(const std::string&  name,const int grade_to_sign,const int grade_to_execute) : m_name(name), m_grade_to_sign(grade_to_sign), m_grade_to_execute(grade_to_execute)
{
    m_signed = false;
    std::cout << "AForm parametr ctor" << std::endl;
}

AForm::AForm(const AForm& obj): m_name(obj.m_name), m_signed(obj.m_signed), m_grade_to_sign(obj.m_grade_to_sign),
m_grade_to_execute(obj.m_grade_to_execute)
{
    
    std::cout << "AForm copy  ctor" << std::endl;
}

AForm & AForm::operator=(const AForm& obj)
{
    if (this != &obj)
    {
       
        m_signed = obj.m_signed;
    }  
    std::cout << "AForm copy assignment operator" << std::endl;
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm default dctor" << std::endl;
}

std::string AForm::getName(void) const
{
    return (m_name);
}

int AForm::getGradeToSign(void) const
{
    return (m_grade_to_sign);
}

int AForm::getGradeToExecute(void)const
{
    return(m_grade_to_execute);
}

bool        AForm::isSigned() const
{
    return (m_signed);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grate too high 1");
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grate too low 150");
}

std::ostream & operator << (std::ostream &op, const AForm &obj)
{
	op << obj.getName()<< ", AForm grade to sign " << obj.getGradeToSign()<< " and grade to execute " << obj.getGradeToExecute() << " and signed " << obj.isSigned();

	return (op);
}

void AForm::beSigned( Bureaucrat& b)
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

void AForm::execute(Bureaucrat const & executor) const
{
    if (m_signed == true && executor.getGrade() <= m_grade_to_execute)
    {
        this->action();
    }
    else
        throw GradeTooLowException();
}