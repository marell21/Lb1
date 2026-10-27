#include "Spouse.h"
#include "Utils.h"

Spouse::Spouse() : FamilyMember()
{
    spouseName = my_strdup("None");
    std::cout << "[Constructor] Spouse (default) created.\n";
}
Spouse::Spouse(const char *f, const char *b, const char *d, int a, const char *sp)
    : FamilyMember(f, b, d, a)
{
    spouseName = my_strdup(sp);
    std::cout << "[Constructor] Spouse (params) created.\n";
}
Spouse::~Spouse()
{
    std::cout << "[Destructor] Spouse destroyed.\n";
    delete[] spouseName;
}
void Spouse::print(std::ostream &os) const
{
    os << "Type: Spouse | FIO: " << fio << " | Age: " << age << " | Spouse: " << spouseName << "\n";
}