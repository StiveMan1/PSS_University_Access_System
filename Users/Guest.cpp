//
// Created by 04024 on 17.03.2021.
//

#include <cstdlib>
#include <iostream>
#include "Guest.h"
using namespace std;
Guest::~Guest() {
    free(this->name);
    free(this->surname);
    free(this->course);
    free(this->courseLevel);
}

void Guest::print(){
    cout<<"Guest : \n\tName : "<<getName()
        <<"\n\tSurname : "<<getSurname()
        <<"\n\tID : "<<getId()
        <<"\n\tAge : "<<getAge()
        <<"\n\tGender : ";
    if(getGender()){
        cout<<"Male";
    }else{
        cout<<"Female";
    }
    cout<<"\n\tAccess Level : "<<AccessLevel(this->access_level);
    cout<<endl;
}