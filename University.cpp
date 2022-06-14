#include "University.h"

University::University(int budget, int numOfProfessor, int numOfStudents, Professor **professor, Student **student) {
    this->budget = budget;
    this->numOfProfessors = numOfProfessor;
    this->numOfStudents = numOfStudents;

    professors = new Professor *[numOfProfessor];
    students = new Student *[numOfStudents];

    for (int i = 0; i < numOfProfessor; ++i) {
        professors[i] = new Professor[1];
    }
    for (int i = 0; i < numOfStudents; ++i) {
        students[i] = new Student[1];
    }

}

University::~University() {
    for (int i = 0; i < numOfProfessors; ++i) {
        delete[] professors[i];
    }
    delete[] professors;

    for (int i = 0; i < numOfStudents; ++i) {
        delete[] students[i];
    }
    delete[] students;
}

University::University(const University &rv) {
    budget = rv.budget;
    numOfProfessors = rv.numOfProfessors;
    numOfStudents = rv.numOfStudents;

    professors = new Professor *[numOfProfessors];
    students = new Student *[numOfStudents];

    for (int i = 0; i < numOfProfessors; ++i) {
        professors[i] = new Professor[1];
    }
    for (int i = 0; i < numOfStudents; ++i) {
        students[i] = new Student[1];
    }
    professors = rv.professors;
    students = rv.students;
}

double University::averageGpa() {
    double sumOfAllGpa = 0;
    for (int i = 0; i < numOfStudents; ++i) {
        sumOfAllGpa += (*(students[i])).gpa();
    }

    return sumOfAllGpa / numOfStudents;
}

double University::averageGpaOfField(std::string field) {
    double sumOfAllGpa = 0;
    double numOfFieldStudents = 0;
    for (int i = 0; i < numOfStudents; ++i) {
        if ((*(students[i])).getFieldOfStudy() == field) {
            numOfFieldStudents++;
            sumOfAllGpa += (*(students[i])).gpa();
        }
    }
    return sumOfAllGpa / numOfFieldStudents;
}

bool University::isEnoughBudget() {
    double sumOfStudentsSalary = 0;
    double sumOfProfessorsSalary = 0;
    double sumOfAllSalaries;

    for (int i = 0; i < numOfStudents; ++i) {
        sumOfStudentsSalary += (*(students[i])).calculateSalary();
    }
    for (int i = 0; i < numOfProfessors; ++i) {
        sumOfProfessorsSalary += (*(students[i])).calculateSalary();
    }
    sumOfAllSalaries = sumOfProfessorsSalary + sumOfStudentsSalary;
    if (budget >= sumOfAllSalaries) {
        return true;
    } else {
        return false;
    }
}

double University::averageMarkOfCourse(std::string CourseName) {
    double sumOfStudentsGrades = 0;
    double numOfCourseStudent = 0;
    for (int i = 0; i < numOfStudents; ++i) {
        if ((*(students[i])).getCourses().getName() == CourseName) {
            sumOfStudentsGrades += (*(students[i])).getCourses().getMark();
            numOfCourseStudent++;
        }
    }
    return sumOfStudentsGrades / numOfCourseStudent;
}

void University::saveToFile(std::string field) {
    int numOfFieldStudents = 0;
    std::ofstream file;
    file.open("bestStudents.txt", std::ofstream::app);

    for (int i = 0; i < numOfStudents; ++i) {
        if ((*(students[i])).getFieldOfStudy() == field) {
            numOfFieldStudents++;
        }
    }
    for (int i = 0; i < numOfFieldStudents; ++i) {
        for (int j = 0; j < numOfFieldStudents; ++j) {
            if ((*(students[i])).gpa() > (*(students[j])).gpa()) {
                file << field << std::endl;
                file << (*(students[i])).getFirstName() << " " << (*(students[i])).getLastName() << std::endl;
                file << (*(students[i])).getId() << std::endl;
            }
        }
    }

}

std::ostream &operator<<(std::ostream &strm, University &u) {
    for (int i = 0; i < u.numOfProfessors; ++i) {
        strm << (*u.professors[i]) << std::endl;
    }
    for (int i = 0; i < u.numOfStudents; ++i) {
        strm << (*u.students[i]) << std::endl;
    }
    return strm;
}



