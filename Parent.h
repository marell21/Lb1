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
    Parent(const Parent &other);
    ~Parent() override;

    Parent &operator=(const Parent &other);

    // Set/Get для специфических полей
    void setChildren(const char *ch);
    const char *getChildren() const;
    void setSpouseName(const char *sp);
    const char *getSpouseName() const;

    void print(std::ostream &os) const override;
    void save(std::ofstream &out) const override;
    void load(std::ifstream &in) override;
    FamilyMember *clone() const override;
};

#endif