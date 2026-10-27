#include "Child.h"
#include "Utils.h"

Child::Child() : FamilyMember()
{
    parents = my_strdup("None");
    std::cout << "[Constructor] Child (default) created.\n";
}
Child::Child(const char *f, const char *b, const char *d, int a, const char *p)
    : FamilyMember(f, b, d, a)
{
    parents = my_strdup(p);
    std::cout << "[Constructor] Child (params) created.\n";
}
Child::~Child()
{
    std::cout << "[Destructor] Child destroyed.\n";
    delete[] parents;
}
void Child::print(std::ostream &os) const
{
    os << "Type: Child | FIO: " << fio << " | Age: " << age << " | Parents: " << parents << "\n";
}