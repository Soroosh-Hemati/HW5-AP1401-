#ifndef HW5_2_STUDENT_H
#define HW5_2_STUDENT_H

#include "Person.h"
#include "Course.h"

class Student : public Person {
private:
    Course *courses;
    std::string fieldOfStudy;
    int numOfCourses;
public:
    Student(std::string firstName, std::string lastName, std::string id, double workHours, std::string fieldOfStudy, int numOfCourses, Course courses[]);

    ~Student();

    Student(const Student &rv);

    friend std::ostream &operator<<(std::ostream &strm, Student &s);

    friend std::istream &operator>>(std::istream &strm, Student &s);

    bool validate(std::string ID) override;

    double gpa() const;

    double calculateSalary() override;

    Student();

    const std::string &getFieldOfStudy() const;

    const Course getCourses() const;

};


#endif //HW5_2_STUDENT_H
