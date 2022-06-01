#include<iostream>
#include<stdexcept>
#include<exception>
#include"Database.h"

using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);
void doDemote(Database& db);

int main(){

    Database employeeDB;
    bool done = false;

    while(!done){

        int selection = displayMenu();
        switch (selection)
        {

        case 0:
            done = true;
            break;
        case 1:
            doHire(employeeDB);
            break;
        case 2:
            doFire(employeeDB);
            break;
        case 3:
            doPromote(employeeDB);
            break;
        case 4:
            employeeDB.displayAll();
            break;
        case 5:
            employeeDB.displayCurrent();
            break;
        case 6:
            employeeDB.displayFormer();
        default:
            std::cerr << "Unknow command!" << std::endl;
            break;

        }
    }


    return 0;
}




int displayMenu(){

    int selection;
    std::cout << std::endl;
    std::cout << "Employee database" << std::endl;
    std::cout << "*****************" << std::endl;
    std::cout << "1) Hire a new employee" << std::endl;
    std::cout << "2) Fire an employee" << std::endl;
    std::cout << "3) Promote an employee" << std::endl;
    std::cout << "4) List all employees" << std::endl;
    std::cout << "5) List all current employees" << std::endl;
    std::cout << "6) List all former employees" << std::endl;
    std::cout << "0) Quit" << std::endl;
    std::cout << "---> ";
    std::cin >> selection;
    return selection;

}

void doHire(Database& db){
    
    std::string firstName;
    std::string lastName;
    
    std::cout << "First name: " << std::endl;
    std::cin >> firstName;
    std::cout << "Last name: " << std::endl;
    std::cin >> lastName;

    db.addEmployee(firstName, lastName);
}

void doFire(Database& db){

    int employeeNumber;

    std::cout << "Employee Number: " << std::endl;
    std::cin >> employeeNumber;

    try{
        
        Employee emp = db.getEmployee(employeeNumber);
        emp.fire();

    }catch(const std::logic_error& e){

        std::cerr << "Unable to fire employee: " << e.what() << std::endl;

    }
}

void doPromote(Database& db){

    int raise;
    int employeeNumber;

    std::cout << "Employee number: " << std::endl;
    std::cin >> employeeNumber;
    std::cout << "New amount: " << std::endl;
    std::cin >> raise;

    try{
        
        Employee emp = db.getEmployee(employeeNumber);
        emp.promote(raise);

    }catch(const std::logic_error& e){

        std::cerr << "Unable to find employee: " << e.what() << std::endl;
    }
}

void doDemote(Database& db){

    int raise;
    int employeeNumber;

    std::cout << "Employee number: " << std::endl;
    std::cin >> employeeNumber;
    std::cout << "Demote : " << std::endl;
    std::cin >> raise;
    
    try{
        
        Employee emp = db.getEmployee(employeeNumber);
        emp.demote(raise);

    }catch(const std::logic_error& e){

        std::cerr << "Unable to find employee: " << e.what() << std::endl;
    }
}