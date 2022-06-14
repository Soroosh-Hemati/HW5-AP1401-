#ifndef HW5_2_UNIVERSITY_H
#define HW5_2_UNIVERSITY_H

#include "Professor.h"
#include "Student.h"
#include "Course.h"
#include <fstream>

class University {
private:
    int budget;
    int numOfProfessors;
    int numOfStudents;
    Professor** professors;
    Student** students;
public:
    University(int budget,int numOfProfessor,int numOfStudents,Professor* professor[],Student* student[]);

    ~University();

    University(const University &rv);

    double averageGpa();

    double averageGpaOfField(std::string field);

    bool isEnoughBudget();

    double averageMarkOfCourse(std::string CourseName);

    void saveToFile(std::string field);

    friend std::ostream &operator<<(std::ostream &strm,University &u);






};


#endif //HW5_2_UNIVERSITY_H
