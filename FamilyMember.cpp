#include "FamilyMember.h"
#include "Utils.h"

FamilyMember::FamilyMember() : age(0)
{
    fio = my_strdup("Unknown");
    birthDate = my_strdup("01.01.2000");
    deathDate = my_strdup("");
    std::cout << "[Constructor] Base FamilyMember (default) created.\n";
}
FamilyMember::FamilyMember(const char *f, const char *b, const char *d, int a) : age(a)
{
    fio = my_strdup(f);
    birthDate = my_strdup(b);
    deathDate = my_strdup(d);
    std::cout << "[Constructor] Base FamilyMember (params) created: " << fio << "\n";
}
FamilyMember::~FamilyMember()
{
    std::cout << "[Destructor] Base FamilyMember destroyed: " << (fio ? fio : "null") << "\n";
    delete[] fio;
    delete[] birthDate;
    delete[] deathDate;
}
void FamilyMember::setFio(const char *f)
{
    delete[] fio;
    fio = my_strdup(f);
}
const char *FamilyMember::getFio() const { return fio; }
int FamilyMember::getAge() const { return age; }