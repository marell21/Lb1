#ifndef CHILD_H
#define CHILD_H
#include "FamilyMember.h"

class Child : public FamilyMember
{
private:
    char *parents;

public:
    Child();
    Child(const char *f, const char *b, const char *d, int a, const char *p);
    ~Child() override;
    void print(std::ostream &os) const override;
};
#endif