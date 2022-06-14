#include <iostream>
#include "Student.h"
#include "Professor.h"
#include "University.h"
#include "Course.h"

using namespace std;

int main() {
    Course c1("AP",3,18);
    Course c2("Physics",3,15);
    Course c3("Math",3,16);
    Course c4("English",3,20);
    Course c5("DataBase",3,17);
    Course c6("Literature",3,18);
    Course c7("DiscreteMath",3,14);


    Course student1Courses[3] = {c1,c2,c3};
    Course student2Courses[3] = {c2,c3,c4};
    Course student3Courses[3] = {c3,c4,c5};
    Course student4Courses[3] = {c6,c7,c1};
    Course student5Courses[3] = {c4,c7,c3};
    Course student6Courses[3] = {c7,c2,c5};
    Course student7Courses[3] = {c2,c1,c4};
    Course student8Courses[3] = {c4,c2,c6};
    Course student9Courses[3] = {c4,c6,c7};
    Course student10Courses[3] = {c3,c5,c7};
    Course student11Courses[3] = {c1,c5,c6};
    Course student12Courses[3] = {c1,c4,c2};


    Student s1("Majid","Nemati","93*@21973",15,"Computer Eng.",3,student1Courses);
    Student s2("Reza","Emami","94*@13298",20,"Computer Eng.",3,student2Courses);
    Student s3("Maryam","Rezavand","96*@92112",12,"Computer Eng.",3,student3Courses);
    Student s4("Heliya","Ghafoori","95*@82032",14,"Computer Eng.",3,student4Courses);
    Student s5("Ali","Ahmadi","89*$77022",8,"Civil Eng.",3,student5Courses);
    Student s6("Leyla","Rahimi","97*$23012",10,"Civil Eng.",3,student6Courses);
    Student s7("Pedram","Roohi","94*$97219",9,"Civil Eng.",3,student7Courses);
    Student s8("Sina","Yousefi","96*$12399",12,"Civil Eng.",3,student8Courses);
    Student s9("Kimiya","Akbari","91*%39721",9,"Industrial Eng.",3,student9Courses);
    Student s10("Javid","Shiri","98*%39218",9,"Industrial Eng.",3,student10Courses);
    Student s11("Amir","Babaei","97*%38921",10,"Industrial Eng.",3,student11Courses);
    Student s12("Nazanin","Hosseini","96*%89312",8,"Industrial Eng.",3,student12Courses);

    Professor p1("Ahmad","Nazemi","85#73211",20,"Assistant Professor");
    Professor p2("Zahra","Rezapoor","86#32913",18,"Associate Professor");
    Professor p3("Asghar","Alizadeh","87#89321",19,"Professor");
    Professor p4("Vida","Nemati","88#93897",20,"Assistant Professor");

    Professor* pp1 = &p1;
    Professor* pp2 = &p2;
    Professor* pp3 = &p3;
    Professor* pp4 = &p4;

    Student* ps1 = &s1;
    Student* ps2 = &s2;
    Student* ps3 = &s3;
    Student* ps4 = &s4;
    Student* ps5 = &s5;
    Student* ps6 = &s6;
    Student* ps7 = &s7;
    Student* ps8 = &s8;
    Student* ps9 = &s9;
    Student* ps10 = &s10;
    Student* ps11 = &s11;
    Student* ps12 = &s12;

    Professor* professors[4] = {pp1,pp2,pp3,pp4};
    Student* students[12] = {ps1,ps2,ps3,ps4,ps5,ps6,ps7,ps8,ps9,ps10,ps11,ps12};

    University uni(10000000,4,12,professors,students);





    return 0;
}
