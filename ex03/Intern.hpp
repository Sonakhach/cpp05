#include <iostream>
#include "AForm.hpp"

class Intern
{

public:
    Intern();
    Intern(const Intern &obj);
    Intern &operator=(const Intern& obj);
    ~Intern();
    AForm * makeForm(const std::string& nameForm, const std::string& target);
private:
    AForm* makeShrubbery(const std::string &target);
    AForm* makeRobotomy(const std::string &target);
    AForm* makePresidential(const std::string &target);
};


