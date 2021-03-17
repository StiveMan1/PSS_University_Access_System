//
// Created by 04024 on 05.03.2021.
//

#include "Person.h"
#include <iostream>
using namespace std;
int Person::last_id = 0;
bool Person::CheckPassword(char* Password){
    return (string)Password == (string)this->password;
}