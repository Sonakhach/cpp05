#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // try
    // {
    //     // Bureaucrat e;
    //     // Form a("Sona", 10, 20);
    //     Bureaucrat d("Lol", 15);
    //     // Bureaucrat b(a);
    //     // e = d;
    //     // a.increment();
    //     // d.decrement();
    //     // e.decrement();
    //     // b.increment();
    //     // std ::cout << a.getGrade() << std::endl;
    //     // std ::cout << d.getGrade() << std::endl;
    //     // std ::cout << e.getGrade() << std::endl;

    //     // std ::cout << a << std::endl;
    //     std ::cout << d << std::endl;
    //     // std ::cout << e << std::endl;
    //     // std ::cout << b << std::endl;

    // }
    // catch(std::exception & e)
    // {
    //     std::cout << e.what() << std::endl;

    // }
    // Bureaucrat b("Sona", 2);
    try
    {
        Bureaucrat a("LOL", 3);
        Form form("Hashiv apranqagir", 15, 20);
        std::cout << form << std::endl;
        a.signForm(form);
        a.signForm(form);
        // b.signForm(form);
        // form.beSigned(a);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    // std::cout << b << std::endl;
    return 0;
}