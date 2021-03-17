//
// Created by 04024 on 05.03.2021.
//

#include <cstdlib>
#include <iostream>
#include "Professor.h"

using namespace std;
Professor::~Professor(){
    free(this->name);
    free(this->surname);
    free(this->subject);
}
char* Professor::getSubject(){
    return this->subject;
}
void Professor::print(){
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
    cout<<"\n\tAccess Level : "<<AccessLevel(this->access_level);
    cout<<endl;
}