#include "zipper.h"
//#include "7zpp.h"

#include <iostream>
#include <string>

#define ARG(RES, ARG, TYPE, ...) (RES[#ARG].count() ? RES[#ARG].as<TYPE>() : TYPE(__VA_ARGS__));

struct Student {
    std::string name;
    int id = 0;
};

int main(int argc, char **argv)
{

    printHello();

    system("pause");
	return 0;
}

void printHello()
{
    std::cout << "Hello World!" << std::endl;

    Student st[3] = { "A", 100, "B", 101, "C", 102 };

    for (int i = 0; i < 3; i++) {
        std::cout << __FUNCTION__ << ": st[" << i << "].name = " << st[i].name << " id = " << st[i].id << std::endl;
    }

    Student* ptr = &st[0];
    std::cout << " :: " << ptr[0].id << std::endl;

    Student stA;
    stA.id = 104;
    stA.name = "D";

    Student* ptrA = &stA;
    std::cout << " :: " << ptrA[0].id << std::endl;
}
