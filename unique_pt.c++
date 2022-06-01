#include<iostream>
#include<memory>
#include "employeestruct.h"



int main(){

    auto emp = std::make_unique<Employee>();

    if(emp){

        emp->first_initial = {'F'};
        emp->last_iniital = {'C'};
        emp->employee_number = {9000};
        emp->salary = {4100};
    }else{

        std::cout << "No memory available\n";
    }

    std::cout << emp->first_initial << std::endl;
    std::cout << emp->last_iniital << std::endl;
    std::cout << emp->employee_number << std::endl;
    std::cout << emp->salary<< std::endl;


    /*smart pointer para array*/
    auto emp2 = std::make_unique<Employee[]>(2);

    

    

    return 0;
}