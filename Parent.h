#ifndef PARENT_H
#define PARENT_H
#include "FamilyMember.h"

class Parent : public FamilyMember
{
private:
    char *children;
    char *spouseName;

public:
    Parent();
    Parent(const char *f, const char *b, const char *d, int a, const char *ch, const char *sp);
    ~Parent() override;
    void print(std::ostream &os) const override;
};
#endif