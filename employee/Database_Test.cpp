#include<iostream>
#include "Database.h"

using namespace Records;

int main(){

    Database myDB;

    Employee& emp1 = myDB.addEmployee("Filipe", "Cruz");
    Employee& emp2 = myDB.addEmployee("Bruna", "Bittar");
    Employee& emp3 = myDB.addEmployee("Marlene", "Barcelos");
    
    emp1.fire();
    emp2.setSalary(3400.00f);
    emp3.setSalary(1200);
    emp3.promote();

    myDB.displayCurrent();




    return 0;
}