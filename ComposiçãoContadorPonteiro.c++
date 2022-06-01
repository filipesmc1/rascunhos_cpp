#include<iostream>

class Course;

class Id final{
    private:
    std::std::string id;
    public:
    Id() = default;
    Id(std::string const&);
    std::string &getId() const { return id; }
}

Id::Id(std::string const &i) : id(i){}

class Student{
    private:
    std::string name;
    static int numStudents;
    static int numCourses;
    Id id;
    Course *course[10];
    public:
    Student() = default;
    Student(Student const&) = delete;
    Student(std::string const &, Course *);
    void setCurrentCourse(Course *);
    void setExitCourse(Course *);
    std::string &getCourse() const;

}

Student::numStudents {0};
Student::numCourses {0};

Student::Student(std::string const &n, std::string const &i, Course *c) : name(n), id(i) {

    course = c;
    c->enrollStudent(this);
    numStudents++;
}
Student::~Student(){

    numStudents--;
    course = nullptr;
}

inline Student::setCurrentCourse(Course *c){

    course[numCourses++] = c;
    numCourses++;
}

inline Student::setExitCourse(Course *c){

    course[numCourses - 1] = nullptr;
    numCourses--;
}

inline Student::getCourse(){

    if(course == nullptr){
        std::cout << "Estudante não matriculado em nenhum curso!" << std::endl;
    }else{

        for(size_t i{0}; i < 10; i++){
            std::cout << course[i] << std::endl;
        }
    }
}

class Course{
    private:
    std::string course;
    Student *student[5];
    public:
    Course() = default;
    Course(Course const &) = delete;
    Course(std::string const &, Student *);
    void enrollStudent(Student const &);
    std::string &getStudents() const;
}

