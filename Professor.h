#ifndef HW5_2_PROFESSOR_H
#define HW5_2_PROFESSOR_H

#include "Person.h"

class Professor : public Person {
private:
    std::string title;
public:
    Professor(std::string firstName, std::string lastName, std::string id, double workHours, std::string title);

    friend std::ostream &operator<<(std::ostream &strm, Professor &p);

    friend std::istream &operator>>(std::istream &strm, Professor &p);

    bool validate (std::string id) override;

    double calculateSalary() override;

    Professor();

};


#endif //HW5_2_PROFESSOR_H
