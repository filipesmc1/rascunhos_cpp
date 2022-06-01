#ifndef DATABASE_H
#define DATABASE_H

#include<iostream>
#include<vector>
#include"Employee.h"

namespace Records{
    const int firstEmployeeNumber{1000};

    class Database{

        public:
            
            Employee& addEmployee(std::string, std::string);
            Employee& getEmployee(int);
            Employee& getEmployee(std::string const&, std::string const&);

            void displayAll() const;
            void displayCurrent() const;
            void displayFormer() const;

        private:

            std::vector<Employee> employees;
            int NextEmployeeNumber = defaultStartingSalary;
    };
}

#endif
