#include "Student.h"

Student::Student(std::string firstName, std::string lastName, std::string id, double workHours,
                 std::string fieldOfStudy, int numOfCourses, Course *courses) : Person(firstName, lastName, id,
                                                                                       workHours) {
    this->fieldOfStudy = fieldOfStudy;
    this->numOfCourses = numOfCourses;
    this->courses = new Course[3];
    this->courses = courses;
    if (!Student::validate(this->id)) {
        std::cout << "Invalid student ID!";
        exit(1);
    }

}

Student::~Student() {
    delete[] courses;
}

Student::Student(const Student &rv) : Person(rv) {
    fieldOfStudy = rv.fieldOfStudy;
    numOfCourses = rv.numOfCourses;
    courses = rv.courses;
}

std::ostream &operator<<(std::ostream &strm, Student &s) {
    strm << s.firstName << " " << s.lastName << '\n' << s.id << '\n' << (int) *s.workHours << '\n' << s.fieldOfStudy
         << '\n' << s.numOfCourses;
    return strm;
}

std::istream &operator>>(std::istream &strm, Student &s) {
    strm >> s.firstName >> s.lastName >> s.id >> *s.workHours >> s.fieldOfStudy >> s.numOfCourses;
    return strm;
}

bool Student::validate(std::string ID) {
    if (ID.size() < 8 || ID.size() > 10) {
        return false;
    } else {
        std::regex reg("(8[4-9]|9[0-9]|00)\\*([^0-9]){1,2}([0-3]|[7-9]){5}");
        return std::regex_match(ID, reg);
    }
}

double Student::gpa() const {
    double gpa = 0;
    double numerator;
    double denominator = 0;
    for (int i = 0; i < numOfCourses; ++i) {
        numerator = courses[i].getUnit() * courses[i].getMark();
        denominator += courses[i].getMark();
    }
    gpa =  numerator / denominator;

    return gpa;
}

double Student::calculateSalary() {
    //calculating salary for a month.
    double moneyPerHour = 20000;
    double dayIncome = (*workHours) * moneyPerHour;
    //assuming a month 30 days and minus fridays
    double salary = dayIncome * 26;
    if (gpa() > 17){
        return salary * 1.1;
    } else {
        return salary;
    }
}

Student::Student() : Person() {

}

const std::string &Student::getFieldOfStudy() const {
    return fieldOfStudy;
}

const Course Student::getCourses() const {
    return *courses;
}



