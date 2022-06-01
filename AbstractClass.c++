#include <iostream>
#include <iomanip>


using std::setprecision;
using std::to_string;

constexpr int MAX = 5;

class LifeForm   
{
private:
   int lifeExpectancy {0};  
public:
   LifeForm() = default;    
   LifeForm(const LifeForm &) = default;
   LifeForm(int life) : lifeExpectancy(life) { }
   virtual ~LifeForm() = default;     
   [[nodiscard]] int GetLifeExpectancy() const { return lifeExpectancy; }
   virtual void Print() const = 0;   
   virtual std::string IsA() const = 0;
   virtual std::string Speak() const = 0;
};

class Cat: public LifeForm
{
private:
   int numberLivesLeft {9};  
   std::string name;
   static constexpr int CAT_LIFE {15};  
public:
   Cat() : LifeForm(CAT_LIFE) { }  
   Cat(int lives) : LifeForm(CAT_LIFE), numberLivesLeft(lives) {  }
   Cat(const std::string &);
   ~Cat() override = default;    
   const std::string &GetName() const { return name; }
   int GetNumberLivesLeft() const { return numberLivesLeft; }
   void Print() const override;   
   std::string IsA() const override { return "Gato"; }
   std::string Speak() const final override { return "Miau!"; }
};

Cat::Cat(const std::string &n) : LifeForm(CAT_LIFE), name(n)
{
}

void Cat::Print() const
{
   std::cout << "\t" << name << " tem " << numberLivesLeft;
   std::cout << " vidas" << std::endl;
}

class Person : public LifeForm
{
private: 
   std::string firstName;
   std::string lastName;
   char middleInitial = '\0';  
   std::string title;
   static constexpr int PERSON_LIFE = 80;  
protected:
   void ModifyTitle(const string &);  
public:
   Person();   
   Person(const std::string &, const std::string &, char, const std::string &);
   Person(const Person &) = default;  
   ~Person() override = default;  
   const std::string &GetFirstName() const { return firstName; }
   const std::string &GetLastName() const { return lastName; }
   const std::string &GetTitle() const { return title; }
   char GetMiddleInitial() const { return middleInitial; }
   void Print() const override;  
   std::string IsA() const override;
   std::string Speak() const override;
};


Person::Person() : LifeForm(PERSON_LIFE)
{
}

Person::Person(const std::string &fn, const std::string &ln, char mi, const std::string &t) :
               LifeForm(PERSON_LIFE), firstName(fn), lastName(ln), middleInitial(mi), title(t)
{
}

void Person::ModifyTitle(const std::string &newTitle)
{
   title = newTitle;
}

void Person::Print() const
{
   std::cout << "\t" << title << " " << firstName << " ";
   std::cout << middleInitial << ". " << lastName << std::endl;
}

std::string Person::IsA() const
{
   return "PEssoa";
}

std::string Person::Speak() const
{
   return "Olá!";
}   

class Student : public Person
{
private: 
   float gpa = 0.0;    
   std::string currentCourse;
   const string studentId;  
   static int numStudents;
public:
   Student();  
   Student(const std::string &, const std::string &, char, const std::string &, float, const std::string &, const std::string &);
   Student(const Student &);  
   ~Student() override;  
   void EarnPhD();  
   float GetGpa() const { return gpa; }
   const std::string &GetCurrentCourse() const { return currentCourse; }
   const std::string &GetStudentId() const { return studentId; }
   void SetCurrentCourse(const std::string &);
   void Print() const final override;
   std::string IsA() const override;
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

Student::Student() : studentId(to_string(numStudents + 100) + "Id")
{
   
   numStudents++;
}



Student::Student(const std::string &fn, const std::string &ln, char mi, const std::string &t,
                 float avg, const std::string &course, const std::string &id) :
                 Person(fn, ln, mi, t), gpa(avg), currentCourse(course), studentId(id)
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

void Student::EarnPhD()
{
   ModifyTitle("Dr.");  
}

void Student::Print() const
{
   std::cout << "\t" << GetTitle() << " " << GetFirstName() << " ";
   std::cout << GetMiddleInitial() << ". " << GetLastName();
   std::cout << " id: " << studentId << "\n\tcom gpa: ";
   std::cout << setprecision(3) <<  " " << gpa << " matriculado em: ";
   std::cout << currentCourse << std::endl;
}

std::string Student::IsA() const
{
   return "Estudante";
}

int main()
{

   LifeForm *entity[MAX] = { };
  
   entity[0] = new Person("Mauro", "Nunes", 'M', "Ms.");
   entity[1] = new Student("João", "Santos", 'Z', "Dr.", 3.95, "C++", "21-MIT");
   entity[2] = new Student("Filipe", "Cruz", 'A', "Ms.", 3.95, "C++", "18-GWU");
   entity[3] = new Cat("Preto");
   entity[4] = new Person("Bruna", "Barcelos", 'R', "Miss");

   for (auto *item : entity)   
   {                              
      std::string << item->Speak();
      std::cout << " Eu sou um " << item->IsA() << std::endl;
      item->Print();           
      std::cout << "\tExpectativa de vida: ";
      std::cout << item->GetLifeExpectancy();
      std::cout << "\n";
   } 

   for (auto *item : entity)   
   {                          
      delete item;    
      item = nullptr;  
   }


   return 0;
}
