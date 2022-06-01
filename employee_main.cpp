#include<iostream>
#include "employeestruct.h"

void fazNada();

int main (){

    Employee emp;

    emp.first_initial = 'F';
    emp.last_iniital = 'C';
    emp.employee_number = 8886;
    emp.salary = 4100;

    fazNada();

    return 0;
}


void fazNada(){
    std::cout << __func__ << std::endl;
}