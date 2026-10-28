#include <iostream>
#include "Keeper.h"
#include "Parent.h"
#include "Child.h"
#include "Spouse.h"

void clearInput()
{
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}
int getIntInput()
{
    int val;
    while (!(std::cin >> val))
    {
        std::cout << "Invalid input. Please enter a number: ";
        clearInput();
    }
    clearInput();
    return val;
}

int main()
{
    FamilyTreeKeeper keeper;
    int choice = -1;
    while (choice != 0)
    {
        std::cout << "\nFAMILY TREE MENU\n1. Add Parent\n2. Add Child\n3. Add Spouse\n4. Print All\n5. Remove by Index\n6. Modify by Index\n7. Save to File\n8. Load from File\n0. Exit\nChoose option: ";
        choice = getIntInput();
        try
        {
            if (choice >= 1 && choice <= 3)
            {
                char fio[256], bDate[256], dDate[256], extra1[256], extra2[256];
                std::cout << "Enter FIO: ";
                std::cin.getline(fio, 256);
                std::cout << "Enter Birth Date: ";
                std::cin.getline(bDate, 256);
                std::cout << "Enter Death Date: ";
                std::cin.getline(dDate, 256);
                std::cout << "Enter Age: ";
                int age = getIntInput();
                if (choice == 1)
                {
                    std::cout << "Enter Children: ";
                    std::cin.getline(extra1, 256);
                    std::cout << "Enter Spouse Name: ";
                    std::cin.getline(extra2, 256);
                    keeper += new Parent(fio, bDate, dDate, age, extra1, extra2);
                }
                else if (choice == 2)
                {
                    std::cout << "Enter Parents: ";
                    std::cin.getline(extra1, 256);
                    keeper += new Child(fio, bDate, dDate, age, extra1);
                }
                else if (choice == 3)
                {
                    std::cout << "Enter Spouse Name: ";
                    std::cin.getline(extra1, 256);
                    keeper += new Spouse(fio, bDate, dDate, age, extra1);
                }
                std::cout << "Added successfully.\n";
            }
            else if (choice == 4)
                keeper.printAll();
            else if (choice == 5)
            {
                std::cout << "Enter index to remove: ";
                int idx = getIntInput();
                keeper.remove(idx);
                std::cout << "Removed.\n";
            }
            else if (choice == 6)
            {
                std::cout << "Enter index to modify: ";
                int idx = getIntInput();
                std::cout << "New type (1-Parent, 2-Child, 3-Spouse): ";
                int type = getIntInput();
                if (type < 1 || type > 3)
                {
                    std::cout << "Cancelled.\n";
                    continue;
                }
                char fio[256], bDate[256], dDate[256], extra1[256], extra2[256];
                std::cout << "Enter FIO: ";
                std::cin.getline(fio, 256);
                std::cout << "Enter Birth Date: ";
                std::cin.getline(bDate, 256);
                std::cout << "Enter Death Date: ";
                std::cin.getline(dDate, 256);
                std::cout << "Enter Age: ";
                int age = getIntInput();
                FamilyMember *newObj = nullptr;
                if (type == 1)
                {
                    std::cout << "Enter Children: ";
                    std::cin.getline(extra1, 256);
                    std::cout << "Enter Spouse Name: ";
                    std::cin.getline(extra2, 256);
                    newObj = new Parent(fio, bDate, dDate, age, extra1, extra2);
                }
                else if (type == 2)
                {
                    std::cout << "Enter Parents: ";
                    std::cin.getline(extra1, 256);
                    newObj = new Child(fio, bDate, dDate, age, extra1);
                }
                else if (type == 3)
                {
                    std::cout << "Enter Spouse Name: ";
                    std::cin.getline(extra1, 256);
                    newObj = new Spouse(fio, bDate, dDate, age, extra1);
                }
                keeper.modify(idx, newObj);
                std::cout << "Modified successfully.\n";
            }
            else if (choice == 7)
            {
                char filename[256];
                std::cout << "Enter filename: ";
                std::cin.getline(filename, 256);
                keeper.saveToFile(filename);
            }
            else if (choice == 8)
            {
                char filename[256];
                std::cout << "Enter filename: ";
                std::cin.getline(filename, 256);
                keeper.loadFromFile(filename);
            }
        }
        catch (const KeeperException &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Standard Error: " << e.what() << std::endl;
        }
    }
    return 0;
}