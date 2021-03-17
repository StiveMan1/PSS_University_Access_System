//
// Created by 04024 on 05.03.2021.
//


#ifndef PSS_AS_STUDENT_H
#define PSS_AS_STUDENT_H

#include "Person.h"

class Student:public Person{
private:
    // courseLevel : Bachelor or master Magistrate
public:
    ~Student();
    Student(){}
    Student(Person *person, int Group, int YearEnter){
        this->id = person->getId();
        this->name = person->getName();
        this->surname = person->getSurname();
        this->gender = person->getGender();
        this->age = person->getAge();
        this->group = Group;
        this->yearEnter = YearEnter;
        this->access_level = 1;
    }
    Student(Student const &person){
        this->id = person.id;
        this->name = person.name;
        this->surname = person.surname;
        this->gender = person.gender;
        this->age = person.age;
        this->group = person.group;
        this->yearEnter = person.yearEnter;
        this->access_level = person.access_level;
    }

    int getGroup();
    int getYearEnter();

    void setGroup(int newGroup);
    void print();
};


#endif //PSS_AS_STUDENT_H
