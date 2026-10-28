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
Spouse::Spouse(const Spouse &other) : FamilyMember(other)
{
    spouseName = my_strdup(other.spouseName);
    std::cout << "[Constructor] Spouse (copy) created.\n";
}
Spouse::~Spouse()
{
    std::cout << "[Destructor] Spouse destroyed.\n";
    delete[] spouseName;
}
Spouse &Spouse::operator=(const Spouse &other)
{
    if (this != &other)
    {
        FamilyMember::operator=(other);
        delete[] spouseName;
        spouseName = my_strdup(other.spouseName);
    }
    return *this;
}

void Spouse::setSpouseName(const char *sp)
{
    delete[] spouseName;
    spouseName = my_strdup(sp);
}
const char *Spouse::getSpouseName() const { return spouseName; }

void Spouse::print(std::ostream &os) const
{
    os << "Type: Spouse | FIO: " << fio << " | Age: " << age << " | Spouse: " << spouseName << "\n";
}
void Spouse::save(std::ofstream &out) const
{
    out << "3\n"
        << fio << "\n"
        << birthDate << "\n"
        << deathDate << "\n"
        << age << "\n"
        << spouseName << "\n";
}
void Spouse::load(std::ifstream &in)
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
    delete[] spouseName;
    spouseName = my_strdup(buffer);
}
FamilyMember *Spouse::clone() const { return new Spouse(*this); }