//
// Created by 04024 on 05.03.2021.
//
#ifndef PSS_AS_PROFESSOR_H
#define PSS_AS_PROFESSOR_H

#import "Person.h"

class Professor:public Person{
public:
    ~Professor();
    Professor(Professor const &person){
        this->id = person.id;
        this->name = person.name;
        this->surname = person.surname;
        this->gender = person.gender;
        this->age = person.age;
        this->subject = person.subject;
        this->access_level = person.access_level;
    }
    Professor(){}
    Professor(Person *person,char* Subject) {
        this->id = person->getId();
        this->name = person->getName();
        this->surname = person->getSurname();
        this->gender = person->getGender();
        this->age = person->getAge();
        this->subject = Subject;
        this->access_level = 3;

    }

    char* getSubject();
    void print();
};


#endif //PSS_AS_PROFESSOR_H
