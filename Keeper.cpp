#include "Keeper.h"
#include "Parent.h"
#include "Child.h"
#include "Spouse.h"
#include "Utils.h"
#include <cstring>

KeeperException::KeeperException(const char *m) { msg = my_strdup(m); }
KeeperException::~KeeperException() { delete[] msg; }
const char *KeeperException::what() const noexcept { return msg; }

FamilyTreeKeeper::FamilyTreeKeeper() : size(0), capacity(2)
{
    members = new FamilyMember *[capacity];
    std::cout << "[Constructor] Keeper (default) created.\n";
}
FamilyTreeKeeper::FamilyTreeKeeper(int initialCapacity) : size(0), capacity(initialCapacity > 0 ? initialCapacity : 2)
{
    members = new FamilyMember *[capacity];
    std::cout << "[Constructor] Keeper (params) created. Capacity: " << capacity << "\n";
}
FamilyTreeKeeper::FamilyTreeKeeper(const FamilyTreeKeeper &other) : size(other.size), capacity(other.capacity)
{
    members = new FamilyMember *[capacity];
    for (int i = 0; i < size; ++i)
        members[i] = other.members[i]->clone();
    std::cout << "[Constructor] Keeper (copy) created.\n";
}
FamilyTreeKeeper::~FamilyTreeKeeper()
{
    for (int i = 0; i < size; ++i)
        delete members[i];
    delete[] members;
    std::cout << "[Destructor] Keeper destroyed.\n";
}
FamilyTreeKeeper &FamilyTreeKeeper::operator=(const FamilyTreeKeeper &other)
{
    if (this != &other)
    {
        for (int i = 0; i < size; ++i)
            delete members[i];
        delete[] members;
        size = other.size;
        capacity = other.capacity;
        members = new FamilyMember *[capacity];
        for (int i = 0; i < size; ++i)
            members[i] = other.members[i]->clone();
    }
    return *this;
}
void FamilyTreeKeeper::resize()
{
    capacity *= 2;
    FamilyMember **newMembers = new FamilyMember *[capacity];
    for (int i = 0; i < size; ++i)
        newMembers[i] = members[i];
    delete[] members;
    members = newMembers;
}
FamilyTreeKeeper &FamilyTreeKeeper::operator+=(FamilyMember *member)
{
    add(member);
    return *this;
}
FamilyMember *FamilyTreeKeeper::operator[](int index)
{
    if (index < 0 || index >= size)
        throw KeeperException("Error: Index out of bounds!");
    return members[index];
}
void FamilyTreeKeeper::add(FamilyMember *member)
{
    if (member == nullptr)
        return;
    if (size == capacity)
        resize();
    members[size++] = member;
}
void FamilyTreeKeeper::remove(int index)
{
    if (index < 0 || index >= size)
        throw KeeperException("Error: Index out of bounds for removal!");
    delete members[index];
    for (int i = index; i < size - 1; ++i)
        members[i] = members[i + 1];
    size--;
}
void FamilyTreeKeeper::modify(int index, FamilyMember *newMember)
{
    if (index < 0 || index >= size)
    {
        delete newMember;
        throw KeeperException("Error: Index out of bounds for modification!");
    }
    delete members[index];
    members[index] = newMember;
}
void FamilyTreeKeeper::printAll() const
{
    if (size == 0)
    {
        std::cout << "Family tree is empty.\n";
        return;
    }
    for (int i = 0; i < size; ++i)
        std::cout << "[" << i << "] " << *members[i];
}
void FamilyTreeKeeper::saveToFile(const char *filename) const
{
    std::ofstream out(filename);
    if (!out.is_open())
        throw KeeperException("Error: Could not open file for saving!");
    out << size << "\n";
    for (int i = 0; i < size; ++i)
        members[i]->save(out);
    out.close();
    std::cout << "Saved successfully.\n";
}
void FamilyTreeKeeper::loadFromFile(const char *filename)
{
    std::ifstream in(filename);
    if (!in.is_open())
        throw KeeperException("Error: Could not open file for loading!");
    for (int i = 0; i < size; ++i)
        delete members[i];
    size = 0;
    int count;
    if (!(in >> count) || count < 0)
        throw KeeperException("Error: File is empty, corrupted, or contains invalid data!");
    in.ignore();
    for (int i = 0; i < count; ++i)
    {
        int type;
        if (!(in >> type))
            throw KeeperException("Error: Unexpected end of file during loading!");
        in.ignore();
        FamilyMember *obj = nullptr;
        if (type == 1)
            obj = new Parent();
        else if (type == 2)
            obj = new Child();
        else if (type == 3)
            obj = new Spouse();
        else
            throw KeeperException("Error: Unknown object type in file!");
        obj->load(in);
        add(obj);
    }
    in.close();
    std::cout << "Loaded successfully.\n";
}