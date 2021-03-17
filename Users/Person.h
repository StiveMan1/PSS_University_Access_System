//
// Created by 04024 on 05.03.2021.
//

#ifndef PSS_AS_PERSON_H
#define PSS_AS_PERSON_H


class Person {
    static int last_id;
protected:
    bool gender = true;
    unsigned int id = 0,age;
    unsigned short access_level = 0;
    char* name;
    char* surname;
    //Student's
    char* course;
    char* courseLevel;
    int group, yearEnter;
    //Professor's
    char* subject;
    //Lab employer's
    int num_groups = 0;
    int* groups = new int[0]();
    char* password;
public:

    Person(bool Gender, char* Name, char* Surname, int Age){
        this->id = Person::last_id++;
        this->name = Name;
        this->surname = Surname;
        this->gender = Gender;
        this->age = Age;
    }
    Person(){}
    Person(Person const &person){
        this->id = person.id;
        this->name = person.name;
        this->surname = person.surname;
        this->gender = person.gender;
        this->age = person.age;
    }
    int getId(){
        return this->id;
    }
    char* getName(){
        return this->name;
    }
    char* getSurname(){
        return this->surname;
    }
    bool getGender(){
        return this->gender;
    }
    int getAge(){
        return this->age;
    }
    int getAccessLevel(){
        return this->access_level;
    }
    virtual bool CheckPassword(char* Password);

    static char* AccessLevel(int level){
        if(level == 1){
            return (char*)("Gray");
        }else if(level == 2){
            return (char*)("Green");
        }else if(level == 3){
            return (char*)("Yellow");
        }else if(level == 4){
            return (char*)("Red");
        }
        return (char*)"non-level";
    }
};


#endif //PSS_AS_PERSON_H
