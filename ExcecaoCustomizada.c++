#include <iostream>
#include <iomanip>

using std::setprecision;
using std::set_terminate;
using std::to_string;
using std::exception; 

constexpr int MAX = 5;

void AppSpecificTerminate()
{
    std::cout << "Uncaught exception. Program terminating" << std::endl;
    exit(1);
}

class StudentException: public exception
{
private:
    int errCode = 0;  
    std::string details;
public:   
    StudentException(const std::string &det, int num): errCode(num), details(det) { }
    const char *what() const noexcept override
    {
        return "Student Exception";
    }
    int GetCode() const { return errCode; }
    const std::string &GetDetails() const { return details; }
};

class Person
{
private:
    std::string firstName;
    std::string lastName;
    char middleInitial = '\0';
    std::string title;
protected:
    void ModifyTitle(const std::string &);
public:
    Person() = default;
    Person(const std::string &, const std::string &, char, const std::string &);

    virtual ~Person() = default;

    const std::string &GetFirstName() const { return firstName; }
    const std::string &GetLastName() const { return lastName; }
    const std::string &GetTitle() const { return title; }
    char GetMiddleInitial() const { return middleInitial; }


    virtual void Print() const;
    virtual void IsA() const;
    virtual void Greeting(const std::string &) const;
};

Person::Person(const std::string &fn, const std::string &ln, char mi, const std::string &t) :
               firstName(fn), lastName(ln), middleInitial(mi), title(t)
{

}


void Person::ModifyTitle(const std::string &newTitle)
{
    title = newTitle;
}

void Person::Print() const
{
    std::cout << title << " " << firstName << " ";
    std::cout << middleInitial << ". " << lastName << std::endl;
}

void Person::IsA() const
{
    std::cout << "Pessoa" << std::endl;
}

void Person::Greeting(const std::string &msg) const
{
    std::cout << msg << std::endl;
}

class Student : public Person
{
private:
    float gpa = 0.0;
    std::string currentCourse;
    const std::string studentId;
    static int numStudents;

    Student();
    Student(const std::string &, const std::string &, char, const std::string &, float, const std::string &, const std::string &);
    Student(const Student &);
    ~Student() override;

    void EarnPhD();
    void SetCurrentCourse(const std::string &);
    bool TakePrerequisites();
    float GetGpa() const { return gpa; }
    const std::string &GetCurrentCourse() const { return currentCourse; }
    const std::string &GetStudentId() const { return studentId; }


    void Print() const override;
    void IsA() const override;
    virtual void Validate();
    virtual void Graduate();

    static int GetNumberStudents();
};

int Student::numStudents = 0;

inline void Student::SetCurrentCourse(const std::string &c)
{
   currentCourse = c;
}

inline int Student::GetNumberStudents()
{
    return numStudents;
}


Student::Student() : studentId(to_std::string(numStudents + 100) + "Id")
{

   numStudents++;
}

Student::Student(const std::string &fn, const std::string &ln, char mi, const std::string &t,
       float avg, const std::string &course, const std::string &id) : Person(fn, ln, mi, t),
                       gpa(avg), currentCourse(course), studentId(id)
{

   numStudents++;
}

Student::Student(const Student &s) : Person(s),
                 gpa(s.gpa), currentCourse(s.currentCourse), studentId(s.studentId)
{
   numStudents++;
}

Student::~Student()
{
   numStudents--;
}

void Student::EarnPhD()
{
    ModifyTitle("Dr.");
}

void Student::Print() const
{

    std::cout << GetTitle() << " " << GetFirstName() << " ";
    std::cout << GetMiddleInitial() << ". " << GetLastName();
    std::cout << " com id: " << studentId << " GPA: ";
    std::cout << setprecision(3) <<  " " << gpa;
    std::cout << " Curso: " << currentCourse << std::endl;
}

void Student::IsA() const
{
    std::cout << "Estudante" << std::endl;
}

void Student::Validate()
{
    throw std::string("Estudante não preenche os pre-requisitos!");
}

bool Student::TakePrerequisites()
{
    return false;
}

void Student::Graduate()
{
   
   if(GetGpa() < 2){
       throw StudentException("Não houve nota o suficiente!", 4);
   }else{
       std::cout << "Graduado!" << std::endl;
   }
   
}

int main()
{
    set_terminate(AppSpecificTerminate);  // register fn.

    Student s1("Filipe", "Cruz", 'G', "Mr", 1.95, "C++", "231GWU");

    try
    {
        s1.Graduate();
    }
    catch (const StudentException &e)
    { 
        std::cout << e.what() << std::endl;
        std::cout << "Código de erro: " << e.GetCode() << "\n" << e.GetDetails() << std::endl;
        exit(1);
    }


    std::cout << "Continuando a execução...." << std::endl;

    return 0;
}
