#include<iostream>
#include"Employee.h"


namespace Records{


    Employee::Employee(std::string const& f, std::string const& l): firstName(f), lastName(l){}

    Employee::Employee(std::string const& first, std::string const& last, int num, bool hired):
        firstName{first}, 
        lastName{last}, 
        mEmployeeNumber{num}, 
        iHired{hired} { }

    
    void Employee::setFirstName(std::string const& first)
    {
        firstName = first;
    }

    void Employee::setLastName(std::string const& last)
    {
        lastName = last;
    }

    void Employee::setEmployeeNumber(int n)
    {
        mEmployeeNumber = n;

    }

    void Employee::setSalary(float s)
    {
        mSalary = s;
    }

    void Employee::demote(int demeritAmount)
    {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::hire()
    {
        iHired = true;
    }

    void Employee::fire()
    {
        iHired = false;
    }

    void Employee::display() const
    {
    std::cout << "Employee: " << getLastName() << ", " << getFirstName() <<std::endl;
    std::cout << (isHired() ? "Current Employee" : "Former Employee") <<std::endl;
    std::cout << "Employee Number: " << getEmployeeNumber() <<std::endl;
    std::cout << "Salary: " << getSalary() <<std::endl;
    }
    
    std::string const& Employee::getFirstName() const
    {
        return firstName;
    }

    std::string const& Employee::getLastName() const
    {
        return lastName;
    }

    float Employee::getSalary() const
    {
        return mSalary;
    }

    bool Employee::isHired() const 
    {
        return iHired;
    }

    int Employee::getEmployeeNumber() const
    {
        return mEmployeeNumber;
    }
}