#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>

namespace Records{
   
    const float defaultStartingSalary = 30000;

    class Employee{

        public:

            Employee() = default;
            Employee(std::string const&, std::string const&);
            Employee(std::string const&, std::string const&, int, bool);
            void promote(int raiseAmount = 1000);
            void demote(int demeritAmount = 1000);
            void hire();
            void fire();
            void display() const;
            
            void setFirstName(std::string const&);
            const std::string &getFirstName() const;

            void setLastName(std::string const&);
            const std::string &getLastName() const;

            void setEmployeeNumber(int);
            int getEmployeeNumber() const;

            void setSalary(float);
            float getSalary() const;

            bool isHired() const;

            
        private:

            std::string firstName;
            std::string lastName;
            int employeeNumber;
            float salary = defaultStartingSalary;
            bool iHired;

    };
}

#endif
