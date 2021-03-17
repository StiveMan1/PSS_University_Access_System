//
// Created by 04024 on 05.03.2021.
//

#include <cstdlib>
#include <iostream>
#include "Student.h"
using namespace std;
Student::~Student() {
    free(this->name);
    free(this->surname);
    free(this->course);
    free(this->courseLevel);
}
int Student::getGroup(){
    return this->group;
}
int Student::getYearEnter(){
    return this->yearEnter;
}
void Student::setGroup(int newGroup){
    this->group = newGroup;
}

void Student::print(){
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
    cout<<"\n\tGroup : "<<getGroup();
    cout<<"\n\tYear Enter in Inno : "<<getYearEnter();
    cout<<"\n\tAccess Level : "<<AccessLevel(this->access_level);
    cout<<endl;
}