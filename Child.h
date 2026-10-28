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
    Child(const Child &other);
    ~Child() override;

    Child &operator=(const Child &other);

    // Set/Get для специфических полей
    void setParents(const char *p);
    const char *getParents() const;

    void print(std::ostream &os) const override;
    void save(std::ofstream &out) const override;
    void load(std::ifstream &in) override;
    FamilyMember *clone() const override;
};

#endif