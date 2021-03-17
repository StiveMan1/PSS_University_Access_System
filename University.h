//
// Created by 04024 on 05.03.2021.
//

#ifndef PSS_AS_UNIVERSITY_H
#define PSS_AS_UNIVERSITY_H


#include "Users/Person.h"
#include "Room.h"

class University {
public:
    int persons_count=1,rooms_count=1;
    int persons_len=0,rooms_len=0;
    Person* persons = new Person[1];
    Room* rooms = new Room[1];
};


#endif //PSS_AS_UNIVERSITY_H
