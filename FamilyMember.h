#ifndef FAMILYMEMBER_H
#define FAMILYMEMBER_H

#include <iostream>
#include <fstream>

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
    FamilyMember(const FamilyMember &other);
    virtual ~FamilyMember();

    FamilyMember &operator=(const FamilyMember &other);

    // Общие Set/Get
    void setFio(const char *f);
    const char *getFio() const;
    int getAge() const;
    void setAge(int a);

    // Чисто виртуальные функции
    virtual void print(std::ostream &os) const = 0;
    virtual void save(std::ofstream &out) const = 0;
    virtual void load(std::ifstream &in) = 0;
    virtual FamilyMember *clone() const = 0;

    friend std::ostream &operator<<(std::ostream &os, const FamilyMember &obj);
};

#endif