#include "Course.h"

Course::Course(std::string name, int unit, double mark) {
    this->mark = new double;
    this->name = name;
    this->unit = unit;
    *this->mark = mark;
}

Course::~Course() {
    delete[] mark;
}

Course::Course(const Course &rv) {
    mark = new double;
    name = rv.name;
    unit = rv.unit;
    *mark = *rv.mark;
}

Course::Course() {}

std::ostream &operator<<(std::ostream &strm, Course &c) {
    strm << c.name << '\n' << c.unit << '\n' << *c.mark;
    return strm;
}

std::istream &operator>>(std::istream &strm, Course &c) {
    strm >> c.name >> c.unit >> *c.mark;
    return strm;
}

const std::string &Course::getName() const {
    return name;
}

void Course::setName(const std::string &name) {
    Course::name = name;
}

int Course::getUnit() const {
    return unit;
}

void Course::setUnit(int unit) {
    Course::unit = unit;
}

double Course::getMark() const {
    return *mark;
}

void Course::setMark(double *mark) {
    Course::mark = mark;
}







