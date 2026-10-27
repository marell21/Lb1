#include <iostream>
#include "Parent.h"
#include "Child.h"
#include "Spouse.h"

int main()
{
    std::cout << "FAMULY TREE\n";

    Parent p("Ivanov Ivan", "01.01.1980", "-", 43, "Petr, Anna", "Maria");
    p.print(std::cout);

    Child c("Petr Ivanov", "05.05.2010", "-", 13, "Ivanov Ivan, Maria");
    c.print(std::cout);

    Spouse s("Maria Ivanova", "10.10.1985", "-", 38, "Ivanov Ivan");
    s.print(std::cout);

    return 0;
}