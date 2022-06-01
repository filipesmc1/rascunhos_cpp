#include<iostream>
#include"Employee.h"

using namespace std;
using namespace Records;

int main()
{
    Employee emp;
    emp.setFirstName("Filipe");
    emp.setLastName("Cruz");
    emp.setEmployeeNumber(78999);
    emp.setSalary(90000);
    emp.promote();
    emp.promote(5600);
    emp.hire();
    emp.display();

    return 0;
}
