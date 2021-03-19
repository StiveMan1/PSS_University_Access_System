//
// Created by 04024 on 05.03.2021.
//

#ifndef PSS_AS_ADMIN_H
#define PSS_AS_ADMIN_H


#include "Person.h"
#include "../Room.h"
#include "../University.cpp"

class Admin :public Person{
private:
    void resizePersons(){
        Person* resizesPersonList = new Person[Innopolis->persons_count*2];
        for(int i=0;i<Innopolis->persons_count;i++){
            resizesPersonList[i] = Innopolis->persons[i];
        }
        Innopolis->persons_count<<=1;
        Innopolis->persons = resizesPersonList;
    }
    void resizeRooms(){
        Room* resizesRoomList = new Room[Innopolis->rooms_count*2];
        for(int i=0;i<Innopolis->rooms_count;i++){
            resizesRoomList[i] = Innopolis->rooms[i];
        }
        Innopolis->rooms_count<<=1;
        Innopolis->rooms = resizesRoomList;
    }

public:
    static University *Innopolis;
    void addNewPerson(Person* person){
        if(Innopolis->persons_count == Innopolis->persons_len+1){
            resizePersons();
        }
        Innopolis->persons[Innopolis->persons_len] = *person;
        Innopolis->persons_len ++;
    }
    void addNewRoom(Room* room){
        if(Innopolis->rooms_count == Innopolis->rooms_len+1){
            resizeRooms();
        }
        Innopolis->rooms[Innopolis->rooms_len] = *room;
        Innopolis->rooms_len ++;
    }

    Admin(Person* person, char* Password){
        this->id = person->getId();
        this->name = person->getName();
        this->surname = person->getSurname();
        this->gender = person->getGender();
        this->age = person->getAge();
        this->password = Password;
        this->access_level = 5;
    }
    Admin(Admin const &admin){
        this->id = admin.id;
        this->name = admin.name;
        this->surname = admin.surname;
        this->age = admin.age;
        this->password = admin.password;
        this->access_level = admin.access_level;
    }
    Admin(){}
    ~Admin();

    void print();


};


#endif //PSS_AS_ADMIN_H
