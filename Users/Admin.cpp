//
// Created by 04024 on 05.03.2021.
//

#include <cstdlib>
#include <iostream>
#include "Admin.h"
using namespace std;
Admin::~Admin(){
    free(this->name);
    free(this->surname);;
    free(this->password);
}
University* Admin::Innopolis = new University();

void Admin::print(){
    cout<<"Admin : \n\tName : "<<getName()
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