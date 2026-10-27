#ifndef SPOUSE_H
#define SPOUSE_H
#include "FamilyMember.h"

class Spouse : public FamilyMember
{
private:
    char *spouseName;

public:
    Spouse();
    Spouse(const char *f, const char *b, const char *d, int a, const char *sp);
    ~Spouse() override;
    void print(std::ostream &os) const override;
};
#endif