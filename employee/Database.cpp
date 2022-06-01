#include<iostream>
#include<stdexcept>
#include"Database.h"

namespace Records{

    Employee& Database::addEmployee(std::string first, std::string last)
    {
        Employee theEmployee{std::move(first), std::move(last)};
        theEmployee.setEmployeeNumber(nextEmployeeNumber);
        theEmployee.hire();
        employees.emplace_back(theEmployee);
        return employees[employees.size() - 1];

    }

    Employee& Database::getEmployee(int id)
    {
        for(auto& emp: employees)
        {
            if(emp.getEmployeeNumber() == id){
                return emp;
            }
        }

        throw std::logic_error("No employee found!");
    }

    Employee& Database::getEmployee(std::string const& f, std::string const& l)
    {
        for(auto& emp: employees){
            if(emp.getFirstName().compare(f) && emp.getLastName().compare(l)){
                return emp;
            }
        }

        throw std::logic_error("No employeer found!");
    }

    void Database::displayAll() const
    {
        for(auto const& e: employees)
        {
            e.display();
        }
    }

    void Database::displayCurrent() const
    {
        for(auto const& e: employees)
        {
            if(e.isHired()){ e.display(); }
        }
    }
    void Database::displayFormer() const
    {
        for(auto const& e: employees)
        {
            if(!e.isHired()){ e.display(); }
        }
    }



}
