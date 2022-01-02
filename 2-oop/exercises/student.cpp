#include <cassert>
#include <stdexcept>

// TODO: Define "Student" class
class Student
{
public:
    Student();
    Student(std::string name, int grade, double gpa) : name_(name), grade_(grade), gpa_(gpa){};
    std::string getName() const;
    int getGrade() const;
    double getGpa() const;
    void setName(std::string name);
    void setGrade(int grade);
    void setGpa(double gpa);

private:
    std::string name_;
    int grade_;
    double gpa_;
};

std::string Student::getName() const
{
    return name_;
}

int Student::getGrade() const
{
    return grade_;
}

double Student::getGpa() const
{
    return gpa_;
}

void Student::setName(std::string name)
{
    this->name_ = name;
}

void Student::setGrade(int grade)
{
    if (grade < 0 || grade > 12)
    {
        throw std::invalid_argument("Grade must be between 0 and 12");
    }
    this->grade_ = grade;
}

void Student::setGpa(double gpa)
{
    if (gpa < 0 || gpa > 4)
    {
        throw std::invalid_argument("GPA must be between 0 and 4");
    }
    this->gpa_ = gpa;
}

// TODO: Test
int main()
{
    Student s1 = Student("John", 10, 3.5);
    assert(s1.getName() == "John");
    assert(s1.getGrade() == 10);
    assert(s1.getGpa() == 3.5);
}