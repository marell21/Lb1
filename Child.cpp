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
Child::Child(const Child &other) : FamilyMember(other)
{
    parents = my_strdup(other.parents);
    std::cout << "[Constructor] Child (copy) created.\n";
}
Child::~Child()
{
    std::cout << "[Destructor] Child destroyed.\n";
    delete[] parents;
}
Child &Child::operator=(const Child &other)
{
    if (this != &other)
    {
        FamilyMember::operator=(other);
        delete[] parents;
        parents = my_strdup(other.parents);
    }
    return *this;
}

void Child::setParents(const char *p)
{
    delete[] parents;
    parents = my_strdup(p);
}
const char *Child::getParents() const { return parents; }

void Child::print(std::ostream &os) const
{
    os << "Type: Child  | FIO: " << fio << " | Age: " << age << " | Parents: " << parents << "\n";
}
void Child::save(std::ofstream &out) const
{
    out << "2\n"
        << fio << "\n"
        << birthDate << "\n"
        << deathDate << "\n"
        << age << "\n"
        << parents << "\n";
}
void Child::load(std::ifstream &in)
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
    delete[] parents;
    parents = my_strdup(buffer);
}
FamilyMember *Child::clone() const { return new Child(*this); }