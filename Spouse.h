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
    Spouse(const Spouse &other);
    ~Spouse() override;

    Spouse &operator=(const Spouse &other);

    // Set/Get для специфических полей
    void setSpouseName(const char *sp);
    const char *getSpouseName() const;

    void print(std::ostream &os) const override;
    void save(std::ofstream &out) const override;
    void load(std::ifstream &in) override;
    FamilyMember *clone() const override;
};

#endif