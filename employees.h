#pragma once
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<vector>
#include"structual_divisions.h"
#include"employees.h"
using namespace std;
#include <windows.h> // ��� HANDLE 
extern HANDLE hConsole;
class employees {
    std::string name;// ���
    int age;// �������
    std::string pol;// ���
    double experience;//���� � �����
    int salary;//��������
    int hoursweek;
public:
    employees();
    employees(std::string name, int age, string pol, double experience, int salary, int hoursweek);
    bool operator<(const employees& other) const;
    void edit_data();
    static void addemployee(std::set<employees>& employees_list);
    static void delete_employee(std::set<employees>& employees_set);
    void print() const;  
};
