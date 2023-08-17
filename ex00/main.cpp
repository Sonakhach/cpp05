#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Sona", 149);
        a.decrement();
        std ::cout << a.getGrade() << std::endl;
        a.decrement();
        // std ::cout << d.getGrade() << std::endl;
        // std ::cout << e.getGrade() << std::endl;

        std ::cout << a << std::endl;

    }
    catch(Bureaucrat::GradeTooHighException & e)
    {
        std::cout << "HIGH\n"<< e.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooLowException & e)
    {
        std::cout << "LOW\n"<< e.what() << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << "NORMAL\n"<< e.what() << std::endl;
    }
    return 0;
}