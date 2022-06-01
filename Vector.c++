#include <iostream>
#include <iomanip>
#include <vector>

using std::setprecision;
using std::to_string;

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
    Person(const Person &) = default;
    Person &operator=(const Person &);
    virtual ~Person() = default;

    const std::string &GetFirstName() const { return firstName; }
    const std::string &GetLastName() const { return lastName; }
    const std::string &GetTitle() const { return title; }
    char GetMiddleInitial() const { return middleInitial; }

    virtual void Print() const; 
    virtual void IsA() const;  
    virtual void Greeting(const string &) const;
};


Person::Person(const std::string &fn, const std::string &ln, char mi, const std::string &t) :
               firstName(fn), lastName(ln), middleInitial(mi), title(t)
{
}

Person &Person::operator=(const Person &p)
{
   if (this != &p)
   {

      firstName = p.firstName;
      lastName = p.lastName;
      middleInitial = p.middleInitial;
      title = p.title;
   }
   return *this;
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
    std::string studentId;
    static int numStudents;
public:
    Student();
    Student(const std::string &, const std::string &, char, const std::string &, float, const std::string &, const std::string &);
    Student(const Student &);
    Student &operator=(const Student &);
    ~Student() override;
    void EarnPhD();  
    float GetGpa() const { return gpa; }
    const std::string &GetCurrentCourse() const { return currentCourse; }
    const std::string &GetStudentId() const { return studentId; }
    void SetCurrentCourse(const string &);
  

    void Print() const override;
    void IsA() const override;

    static int GetNumberStudents() { return numStudents; }
};


int Student::numStudents = 0;


inline void Student::SetCurrentCourse(const std::string &c)
{
    currentCourse = c;
}


Student::Student() : studentId(to_string(numStudents + 100) + "Id")
{

   numStudents++;
}

Student::Student(const std::string &fn, const std::string &ln, char mi, const std::string &t, float avg, const std::string &course,
                 const std::string &id) : Person(fn, ln, mi, t), gpa(avg), currentCourse(course), studentId(id)
{
    numStudents++;
}

Student::Student(const Student &s) : Person(s), gpa(s.gpa), currentCourse(s.currentCourse), studentId(s.studentId)
{
    numStudents++;
}

Student::~Student()
{
    numStudents--;
}

Student &Student::operator=(const Student &s)
{
   if (this != &s)
   {
      Person::operator=(s);


      gpa = s.gpa;
      currentCourse = s.currentCourse;
      studentId = s.studentId;

   }
   return *this;
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
    cout << "Estudante" << endl;
}


bool operator<(const Student &s1, const Student &s2)
{
    return (s1.GetGpa() < s2.GetGpa());
}

bool operator==(const Student &s1, const Student &s2)
{
    return (s1.GetGpa() == s2.GetGpa());
}

int main()
{
    std::vector<Student> studentBody1, studentBody2;

    studentBody1.push_back(Student("Filipe", "Cruz", 'M', "Dr.", 3.8, "C++", "178PSU"));
    studentBody1.push_back(Student("Marcia", "Sato", 'B', "Dr.", 3.9, "C++", "272PSU"));
    studentBody1.push_back(Student("Mario", "Ferreira", 'R', "Ms.", 3.4, "C++", "299TU"));


    for (int i = 0; i < studentBody1.size(); i++)   
        studentBody1[i].Print();

    studentBody2 = studentBody1;
    if (studentBody1 == studentBody2)
        std::cout << "Vectors iguais!" << std::endl;

    cout << "Receber PhD" << endl;
    for (auto iter = studentBody2.begin(); iter != studentBody2.end(); iter++)
        (*iter).EarnPhD();

    for (const auto &student : studentBody2)
        student.Print();
   

    if (!studentBody1.empty())
        studentBody1.clear();

    return 0;
}
