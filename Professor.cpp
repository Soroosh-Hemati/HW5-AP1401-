#include "Professor.h"

Professor::Professor(std::string firstName, std::string lastName, std::string id, double workHours, std::string title)
        : Person(firstName, lastName, id, workHours) {
    if (title == "Instructor" || title == "Assistant Professor") {
        this->title = title;
    } else if (title == "Associate Professor" || title == "Professor") {
        this->title = title;
    } else {
        std::cout << "Invalid title!";
        exit(1);
    }
    if (!Professor::validate(this->id)) {
        std::cout << "Invalid professor ID!";
        exit(1);
    }

}

std::ostream &operator<<(std::ostream &strm, Professor &p) {
    strm << p.title << '\n' << p.firstName << " " << p.lastName << '\n' << p.id << '\n' << *p.workHours;
    return strm;
}

std::istream &operator>>(std::istream &strm, Professor &p) {
    strm >> p.title >> p.firstName >> p.lastName >> p.id >> *p.workHours;
    return strm;
}

bool Professor::validate(std::string id) {
    if (id.size() != 8) {
        return false;
    } else {
        std::regex reg("(8[4-9]|9[0-9]|00)\\#([0-3]|[7-9]){5}");
        return std::regex_match(id, reg);
    }
}

double Professor::calculateSalary() {
    //calculating salary for a month.
    int moneyPerHour = 50000;
    if (title == "Instructor") {
        moneyPerHour += 10000;
    } else if (title == "Assistant Professor") {
        moneyPerHour += 20000;
    } else if (title == "Associate Professor") {
        moneyPerHour += 30000;
    } else if (title == "Professor") {
        moneyPerHour += 40000;
    }
    double dayIncome = (*workHours) * moneyPerHour;
    //assuming a month 30 days and minus fridays
    double salary = dayIncome * 26;
    return (int) salary;
}

Professor::Professor() : Person() {

}
