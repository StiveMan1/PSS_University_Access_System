//
// Created by 04024 on 05.03.2021.
//

#ifndef PSS_AS_LAB_EMPLOYEES_H
#define PSS_AS_LAB_EMPLOYEES_H


#include "Person.h"

class lab_employees:public Person{
public:
    ~lab_employees();
    lab_employees(){}
    lab_employees(Person *person,char* Subject) {
        this->id = person->getId();
        this->name = person->getName();
        this->surname = person->getSurname();
        this->gender = person->getGender();
        this->age = person->getAge();
        this->subject = Subject;
        this->access_level = 3;
    }

    char* getSubject();
    void getGroups();
    void setGroups(int* newGroups,int num_groups);
    void print();
};

#endif //PSS_AS_LAB_EMPLOYEES_H
