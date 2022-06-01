#include <iostream>

using std::to_string;

class LifeForm
{
private:
   int lifeExpectancy = 0;  
public:
   LifeForm() = default;
   LifeForm(int life) : lifeExpectancy(life) { std::cout << "Costrutor lifeform" << std::endl;}
   LifeForm(const LifeForm &form) = default; 

   virtual ~LifeForm() { std::cout << "LifeForm Destructor " << std::endl;}
   [[nodiscard]] int GetLifeExpectancy() const { return lifeExpectancy; }

   virtual void Print() const = 0;
   virtual std::string IsA() const = 0;
   virtual std::string Speak() const = 0;
};

class Horse: public LifeForm
{
private:
   std::string name;
   static constexpr int HORSE_LIFE = 35;
public:
   Horse(): LifeForm(HORSE_LIFE) { }
   Horse(const std::string &n);
   const std::string &GetName() const { return name; }
   void Print() const override;
   std::string IsA() const override;
   std::string Speak() const override;
};

Horse::Horse(const string &n) : LifeForm(HORSE_LIFE), name(n)
{
    std::cout << "Costrutor Horse" << std::endl;
}


void Horse::Print() const
{
   std::cout << name << std::endl;
}

std::string Horse::IsA() const
{
   return "Cavalo";
}

std::string Horse::Speak() const
{
   return "Rinchar!";
}

class Person: public LifeForm
{
private:
   std::string firstName;
   std::string lastName;
   char middleInitial = '\0';
   std::string title;
   static constexpr int PERSON_LIFE = 80;
protected:
   void ModifyTitle(const std::string &);
public:
   Person();
   Person(const std::string &, const std::string &, char, const std::string &);
   Person(const Person &) = default;

   // inline function definitions
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

Person::Person(const std::string &fn, const std::string &ln, char mi, const std::string &t) : LifeForm(PERSON_LIFE),
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

std::string Person::IsA() const
{  
    return "Pessoa";
}

std::string Person::Speak() const
{  
    return "Olá!";
}

class Centaur: public Person, public Horse
{
private:
   static constexpr int CENTAUR_LIFE = 1000;
public:
   Centaur();
   Centaur(const std::string &, const std::string &, char = ' ', const std::string & = "Criatura Mitologica");
   Centaur(const Centaur &c): Person(c), Horse(c) { }
   void Print() const override;
   std::string IsA() const override;
   std::string Speak() const override;
};


Centaur::Centaur(const std::string &fn, const std::string &ln, char mi, const std::string &title):
                 Person(fn, ln, mi, title), Horse(fn)
                 
{
   std::cout << "Centauro constructor" << std::endl;
}

void Centaur::Print() const
{
   std::cout << "Meu nome é " << GetFirstName();
   std::cout << ".  Eu sou um " << GetTitle() << std::endl;
}

std::string Centaur::IsA() const
{ 
   return "Centauro";
}


std::string Centaur::Speak() const
{
   return "Rincha e fala: nosso bug de cada dia!";
} 

int main()
{
   Centaur beast("Wild", "Man");
   std::cout << beast.Speak() << std::endl;
   std::cout << "Eu sou " << beast.IsA() << ". ";
   beast.Print();

   return 0;
}
