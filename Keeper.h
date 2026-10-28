#ifndef KEEPER_H
#define KEEPER_H

#include "FamilyMember.h"
#include <exception>

class KeeperException : public std::exception
{
private:
    char *msg;

public:
    KeeperException(const char *m);
    ~KeeperException();
    const char *what() const noexcept override;
};

class FamilyTreeKeeper
{
private:
    FamilyMember **members;
    int size;
    int capacity;
    void resize();

public:
    FamilyTreeKeeper();
    FamilyTreeKeeper(int initialCapacity);
    FamilyTreeKeeper(const FamilyTreeKeeper &other);
    ~FamilyTreeKeeper();

    FamilyTreeKeeper &operator=(const FamilyTreeKeeper &other);
    FamilyTreeKeeper &operator+=(FamilyMember *member);
    FamilyMember *operator[](int index);

    void add(FamilyMember *member);
    void remove(int index);
    void modify(int index, FamilyMember *newMember);
    void printAll() const;
    void saveToFile(const char *filename) const;
    void loadFromFile(const char *filename);
};

#endif