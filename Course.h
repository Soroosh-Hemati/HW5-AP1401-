#ifndef HW5_2_COURSE_H
#define HW5_2_COURSE_H

#include <string>
#include <iostream>

class Course {
private:
    std::string name;
    int unit;
    double *mark;
public:
    Course(std::string name, int unit, double mark);

    ~Course();

    Course(const Course &rv);

    Course();

    friend std::ostream &operator<<(std::ostream &strm, Course &c);

    friend std::istream &operator>>(std::istream &strm, Course &c);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getUnit() const;

    void setUnit(int unit);

    double getMark() const;

    void setMark(double *mark);


};


#endif //HW5_2_COURSE_H
