#include "Person.h"

Person::Person(std::string firstName, std::string lastName, std::string id, double workHours) {
    this->workHours = new double;
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = id;
    *this->workHours = workHours;
    if (!validate(this->id)){
        std::cout << "Invalid person ID!";
        exit(1);
    }
}

Person::~Person() {
    delete workHours;
}

Person::Person(const Person &rv) {
    workHours = new double;
    firstName = rv.firstName;
    lastName = rv.lastName;
    id = rv.id;
    *workHours = *rv.workHours;
}

std::ostream &operator<<(std::ostream &strm, Person &p) {
    strm << p.firstName << " " << p.lastName << '\n' << p.id << '\n' << *p.workHours;
    return strm;
}

std::istream &operator>>(std::istream &strm, Person &p) {
    strm >> p.firstName >> p.lastName >> p.id >> *p.workHours;
    return strm;
}

const std::string &Person::getFirstName() const {
    return firstName;
}

void Person::setFirstName(const std::string &firstName) {
    Person::firstName = firstName;
}

const std::string &Person::getLastName() const {
    return lastName;
}

void Person::setLastName(const std::string &lastName) {
    Person::lastName = lastName;
}

const std::string &Person::getId() const {
    return id;
}

void Person::setId(const std::string &id) {
    Person::id = id;
}

double Person::getWorkHours() const {
    return *workHours;
}

void Person::setWorkHours(double *workHours) {
    Person::workHours = workHours;
}

bool Person::operator==(const Person &rv) {
    if (this->id == rv.id && this->firstName == rv.firstName) {
        return true;
    } else {
        return false;
    }
}

bool Person::validate(std::string ID) {
    if (ID.size() < 8 || ID.size() > 10) {
        return false;
    } else {
        std::regex reg("(8[4-9]|9[0-9]|00)([^0-9]){1,3}([0-3]|[7-9]){5}");
        return std::regex_match(ID, reg);
    }
}

double Person::calculateSalary() {
    //calculating salary for a month.
    double moneyPerHour = 10000;
    double dayIncome = (*workHours) * moneyPerHour;
    //assuming a month 30 days and minus fridays
    double salary = dayIncome * 26;
    return  salary;
}

Person::Person() {

}



