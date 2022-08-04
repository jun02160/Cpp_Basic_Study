#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    char* name;
    int age;

public:
    Person(char* myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }
    Person()
    {
        name = NULL;
        age = 0;
        cout << "called Person()" << endl;
    }
    void SetPersonInfo(char* myname, int myage)
    {
        name = myname;
        age = myage;
    }
    void ShowPersonInfo() const
    {
        cout << "�̸�: " << name << ", ";
        cout << "����: " << age << endl;
    }
    ~Person()
    {
        delete[] name;
        cout << "called destructor!" << endl;
    }
};

int main()
{
    // �� ���Ұ� ��ü Ŭ���� Ÿ������ �̷���� ��ü �迭
    Person parr[3];
    char nameStr[100];
    char* strptr;
    int age;
    int len;

    for (int i = 0; i < 3; i++)
    {
        cout << "�̸�: ";
        cin >> nameStr;
        cout << "����: ";
        cin >> age;
        len = strlen(nameStr) + 1;

        strptr = new char[len];
        strcpy(strptr, nameStr);
        parr[i].SetPersonInfo(strptr, age);
    }

    parr[0].ShowPersonInfo();
    parr[1].ShowPersonInfo();
    parr[2].ShowPersonInfo();
    return 0;
}