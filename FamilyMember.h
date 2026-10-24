#ifndef FAMILYMEMBER_H
#define FAMILYMEMBER_H
#include <iostream>

class FamilyMember
{
protected:
    char *fio;
    char *birthDate;
    char *deathDate;
    int age;

public:
    FamilyMember();
    FamilyMember(const char *f, const char *b, const char *d, int a);
    virtual ~FamilyMember();

    void setFio(const char *f);
    const char *getFio() const;
    int getAge() const;

    // плюс конструктор копирования, иначе строки будут удаляться дважды
    virtual void print(std::ostream &os) const = 0;
};
#endif