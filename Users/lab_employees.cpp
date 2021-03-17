//
// Created by 04024 on 05.03.2021.
//

#include "lab_employees.h"
#include <cstdlib>
#include <iostream>

using namespace std;

lab_employees::~lab_employees(){
    free(this->name);
    free(this->surname);
    free(this->subject);
    free(this->groups);
}
char* lab_employees::getSubject(){
    return this->subject;
}
void lab_employees::getGroups(){

    cout<<"\n\tNumber of Groups : "<<this->num_groups;
    cout<<"\n\t Groups : ";
    for(int i=0;i<this->num_groups;i++){
        cout<<this->groups[i];
        if(i+1 != this->num_groups){
            cout<<", ";
        }
    }


}
void lab_employees::setGroups(int* newGroups,int num_groups){
    this->num_groups = num_groups;
    this->groups = newGroups;
}
void lab_employees::print(){
    cout<<"Student : \n\tName : "<<getName()
        <<"\n\tSurname : "<<getSurname()
        <<"\n\tID : "<<getId()
        <<"\n\tAge : "<<getAge()
        <<"\n\tGender : ";
    if(getGender()){
        cout<<"Male";
    }else{
        cout<<"Female";
    }
    cout<<"\n\tSubject : "<<getSubject();
    getGroups();
    cout<<"\n\tAccess Level : "<<AccessLevel(this->access_level);
    cout<<endl;
}