//
// Created by 04024 on 17.03.2021.
//

#ifndef PSS_AS_GUEST_H
#define PSS_AS_GUEST_H

#include "Person.h"

class Guest:public Person{
private:
    // courseLevel : Bachelor or master Magistrate
public:
    ~Guest();
    Guest(){}
    Guest(Person *person){
        this->id = person->getId();
        this->name = person->getName();
        this->surname = person->getSurname();
        this->gender = person->getGender();
        this->age = person->getAge();
        this->access_level = 2;
    }
    Guest(Guest const &person){
        this->id = person.id;
        this->name = person.name;
        this->surname = person.surname;
        this->gender = person.gender;
        this->age = person.age;
        this->access_level = person.access_level;
    }

    void print();
};

#endif //PSS_AS_GUEST_H
