//
// Created by 04024 on 05.03.2021.
//

#ifndef PSS_AS_ROOM_H
#define PSS_AS_ROOM_H


#include "Users/Person.h"

class Room {
private:
    char* name;
    unsigned int standardAccess = 1;
    int specialAccessedUsers_len = 0,specialAccessedUsers_count=1;
    unsigned int* specialAccessedUsers = new unsigned int[1];
    void resizeAccess(){
        unsigned int* newSpecialAccessedUsers = new unsigned int[specialAccessedUsers_count*2];
        for(int i=0;i<specialAccessedUsers_count;i++){
            newSpecialAccessedUsers[i] = specialAccessedUsers[i];
        }
        specialAccessedUsers_count<<=1;
        specialAccessedUsers = newSpecialAccessedUsers;
    }
public:

    Room(){};
    Room(char* Name,int Room_id,unsigned int StandardAccess) {
        this->name = Name;
        this->standardAccess = StandardAccess;
        this->room_id = Room_id;
    }
    void addInAccessed(unsigned int id){
        for(int i=0;i<specialAccessedUsers_len;i++){
            if(specialAccessedUsers[i] == id){
                return;
            }
        }
        if(specialAccessedUsers_len + 1 == specialAccessedUsers_count){
            resizeAccess();
        }
        specialAccessedUsers[specialAccessedUsers_len] = id;
        specialAccessedUsers_len++;
    }
    void removeAccess(unsigned int id){
        unsigned int* newSpecialAccessedUsers = new unsigned int[specialAccessedUsers_count];
        for(int i=0,j = 0;i<specialAccessedUsers_len;i++){
            if(specialAccessedUsers[i] != id){
                newSpecialAccessedUsers[i-j] = specialAccessedUsers[i];
            }else{
                j++;
            }
        }
        specialAccessedUsers = newSpecialAccessedUsers;
        specialAccessedUsers_len --;
    }

    int room_id;
    bool canEnter(const Person person);
    char* getAccessLevel(){
        return Person::AccessLevel(this->standardAccess);
    }
    char* getName(){
        return this->name;
    }
};


#endif //PSS_AS_ROOM_H
