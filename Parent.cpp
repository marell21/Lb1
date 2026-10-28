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
Parent::Parent(const Parent &other) : FamilyMember(other)
{
    children = my_strdup(other.children);
    spouseName = my_strdup(other.spouseName);
    std::cout << "[Constructor] Parent (copy) created.\n";
}
Parent::~Parent()
{
    std::cout << "[Destructor] Parent destroyed.\n";
    delete[] children;
    delete[] spouseName;
}
Parent &Parent::operator=(const Parent &other)
{
    if (this != &other)
    {
        FamilyMember::operator=(other);
        delete[] children;
        delete[] spouseName;
        children = my_strdup(other.children);
        spouseName = my_strdup(other.spouseName);
    }
    return *this;
}

void Parent::setChildren(const char *ch)
{
    delete[] children;
    children = my_strdup(ch);
}
const char *Parent::getChildren() const { return children; }
void Parent::setSpouseName(const char *sp)
{
    delete[] spouseName;
    spouseName = my_strdup(sp);
}
const char *Parent::getSpouseName() const { return spouseName; }

void Parent::print(std::ostream &os) const
{
    os << "Type: Parent | FIO: " << fio << " | Age: " << age << " | Children: " << children << " | Spouse: " << spouseName << "\n";
}
void Parent::save(std::ofstream &out) const
{
    out << "1\n"
        << fio << "\n"
        << birthDate << "\n"
        << deathDate << "\n"
        << age << "\n"
        << children << "\n"
        << spouseName << "\n";
}
void Parent::load(std::ifstream &in)
{
    char buffer[256];
    in.getline(buffer, 256);
    delete[] fio;
    fio = my_strdup(buffer);
    in.getline(buffer, 256);
    delete[] birthDate;
    birthDate = my_strdup(buffer);
    in.getline(buffer, 256);
    delete[] deathDate;
    deathDate = my_strdup(buffer);
    in >> age;
    in.ignore();
    in.getline(buffer, 256);
    delete[] children;
    children = my_strdup(buffer);
    in.getline(buffer, 256);
    delete[] spouseName;
    spouseName = my_strdup(buffer);
}
FamilyMember *Parent::clone() const { return new Parent(*this); }