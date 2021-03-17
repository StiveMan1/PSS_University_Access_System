//
// Created by 04024 on 05.03.2021.
//

#include "Room.h"

bool Room::canEnter(Person person){
    if(person.getAccessLevel() >= standardAccess){
        return true;
    }
    for(int i=0;i<specialAccessedUsers_len;i++){
        if(specialAccessedUsers[i] == person.getAccessLevel()){
            return true;
        }
    }
    return false;
}