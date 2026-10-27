#include "Parent.h"
#include "Utils.h"

Parent::Parent() : FamilyMember()
{
    children = my_strdup("None");
    spouseName = my_strdup("None");
    std::cout << "[Constructor] Parent (default) created.\n";
}
Parent::Parent(const char *f, const char *b, const char *d, int a, const char *ch, const char *sp)
    : FamilyMember(f, b, d, a)
{
    children = my_strdup(ch);
    spouseName = my_strdup(sp);
    std::cout << "[Constructor] Parent (params) created.\n";
}
Parent::~Parent()
{
    std::cout << "[Destructor] Parent destroyed.\n";
    delete[] children;
    delete[] spouseName;
}
void Parent::print(std::ostream &os) const
{
    os << "Type: Parent | FIO: " << fio << " | Age: " << age << " | Children: " << children << "\n";
}