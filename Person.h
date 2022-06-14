#ifndef HW5_2_PERSON_H
#define HW5_2_PERSON_H

#include <string>
#include <iostream>
#include <regex>


class Person {
protected:
    std::string firstName, lastName, id;
    double *workHours;
public:
    Person(std::string firstName, std::string lastName, std::string id, double workHours);

    ~Person();

    Person(const Person &rv);

    friend std::ostream &operator<<(std::ostream &strm, Person &p);

    friend std::istream &operator>>(std::istream &strm, Person &p);

    void setFirstName(const std::string &firstName);

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    const std::string &getId() const;

    void setId(const std::string &id);

    double getWorkHours() const;

    void setWorkHours(double *workHours);

    bool operator==(const Person &rv);

    virtual bool validate(std::string ID);

    virtual double calculateSalary();

    Person();


};


#endif //HW5_2_PERSON_H
