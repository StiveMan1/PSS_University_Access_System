#include <iostream>
#include "Room.h"
#include "Users/Person.h"
#include "Users/Admin.h"
#include "Users/Professor.h"
#include "Users/lab_employees.h"
#include "Users/Student.h"
#include "University.h"
using namespace std;

Admin* root = nullptr;
void init_step(){
    char *name = (char*)"Admin";
    char* surname = (char*)"Admin";
    char* pass1 = (char*)"toor";
    Person* first_person = new Person(true,name,surname,20);
    Admin* first_admin = new Admin(first_person,pass1);
    first_admin->addNewPerson(first_admin);

}
void GetAdmin(){
    string name,surname;
    cout<<"Name : \n";
    cin>>name;
    cout<<"Surname : \n";
    cin>>surname;
    bool tor = true;
    for(int i=0;i<Admin::Innopolis->persons_len;i++){
        if(Admin::Innopolis->persons[i].getName() == name
           && Admin::Innopolis->persons[i].getSurname() == surname) {

            tor = false;
            ((Admin *)&(Admin::Innopolis->persons[i]))->print();
            break;
        }
    }
    if(tor){
        cout<<"Not in system\n";
    }
}
void Login(){
    string login, password;
    cout << "Name : \n";
    cin >> login;
    cout << "Password : \n";
    cin >> password;
    bool tor = false;
    for(int i=0;i<Admin::Innopolis->persons_len;i++){
        if(login == (string)(Admin::Innopolis->persons[i].getName())){
            if(Admin::Innopolis->persons[i].CheckPassword(&password[0])) {
                tor = true;
                root = (Admin *)&(Admin::Innopolis->persons[i]);
                root->print();
                break;
            }
        }
    }
    if(tor){
        cout<<"You are in\n";
    }else{
        cout<<"Login fail\n";
    }
}
void GetStudent(){
    string name,surname;
    cout<<"Name : \n";
    cin>>name;
    cout<<"Surname : \n";
    cin>>surname;
    bool tor = true;
    for(int i=0;i<Admin::Innopolis->persons_len;i++){
        if(Admin::Innopolis->persons[i].getName() == name
           && Admin::Innopolis->persons[i].getSurname() == surname) {

            tor = false;
            ((Student *)&(Admin::Innopolis->persons[i]))->print();
            break;
        }
    }
    if(tor){
        cout<<"Not in system\n";
    }
}
void GetLabEmployees(){
    string name,surname;
    cout<<"Name : \n";
    cin>>name;
    cout<<"Surname : \n";
    cin>>surname;
    bool tor = true;
    for(int i=0;i<Admin::Innopolis->persons_len;i++){
        if(Admin::Innopolis->persons[i].getName() == name
           && Admin::Innopolis->persons[i].getSurname() == surname) {

            tor = false;
            ((lab_employees *)&(Admin::Innopolis->persons[i]))->print();
            break;
        }
    }
    if(tor){
        cout<<"Not in system\n";
    }
}
void GetProfessor(){
    string name,surname;
    cout<<"Name : \n";
    cin>>name;
    cout<<"Surname : \n";
    cin>>surname;
    bool tor = true;
    for(int i=0;i<Admin::Innopolis->persons_len;i++){
        if(Admin::Innopolis->persons[i].getName() == name
           && Admin::Innopolis->persons[i].getSurname() == surname) {

            tor = false;
            ((Professor *)&(Admin::Innopolis->persons[i]))->print();
            break;
        }
    }
    if(tor){
        cout<<"Not in system\n";
    }
}
void AddNewRoom(){
    char* name = new char[100];
    cout<<"Room Name : \n";
    cin>>name;
    int id;
    cout<<"Room number : \n";
    cin>>id;
    int access;
    cout<<"Standard Access level for Room : \n";
    cin>>access;
    root->addNewRoom(new Room(name,id,access));
}
void AddNewUser(){
    string gender,lol,type;
    int age;
    cout<<"Type (Admin, Student, lab_employees, Professor) : \n";
    cin>>type;

    cout<<"Name : \n";
    char* name1 = new char[100];
    cin>>name1;
    cout<<"Surname : \n";
    char* surname1 = new char[100];
    cin>>surname1;
    cout<<"Gender(Male, Female) : \n";
    cin>>gender;
    cout<<"Age : \n";
    cin>>age;
    Person* newUser = new Person((bool)(gender=="Male"),name1,surname1,age);
    if(type == "Admin"){
        char* password = new char[100];
        cout<<"Password : \n";
        cin>>password;
        root->addNewPerson(new Admin(newUser,password));
    }else if(type == "Student"){
        int group,year;
        cout<<"year entered in Inno : \n";
        cin>>year;
        cout<<"Group : \n";
        cin>>group;
        root->addNewPerson(new Student(newUser,group,year));
    }else if(type == "lab_employees"){
        char* subject = new char[100];
        cout<<"Subject : \n";
        cin>>subject;
        root->addNewPerson(new lab_employees(newUser,subject));
    }else if(type == "Professor"){
        char* subject = new char[100];
        cout<<"Subject : \n";
        cin>>subject;
        root->addNewPerson(new Professor(newUser,subject));
    }
}
void CanUserEnter(){
    string name,surname;
    int room_id;
    cout<<"Name : \n";
    cin>>name;
    cout<<"Surname : \n";
    cin>>surname;
    Person *user = nullptr;
    bool tor = true;
    for(int i=0;i<Admin::Innopolis->persons_len;i++){
        if(Admin::Innopolis->persons[i].getName() == name && Admin::Innopolis->persons[i].getSurname() == surname){
            tor = false;
            user = &Admin::Innopolis->persons[i];
            break;
        }
    }
    if(tor){
        cout<<"No such User\n";
        return;
    }
    cout<<"Room number : \n";
    cin>>room_id;
    for(int i=0;i<Admin::Innopolis->rooms_len;i++){
        if(Admin::Innopolis->rooms[i].room_id == room_id){
            if(Admin::Innopolis->rooms[i].canEnter(*user)){
                cout<<"Can Enter\n";
            }else{
                cout<<"Can not Enter\n";
            }
            return;
        }
    }
    cout<<"No such room\n";
}
void AddSpecialAccess(){
    string name,surname;
    int room_id,user_id;
    cout<<"Name : \n";
    cin>>name;
    cout<<"Surname : \n";
    cin>>surname;
    bool tor = true;
    for(int i=0;i<Admin::Innopolis->persons_len;i++){
        if(Admin::Innopolis->persons[i].getName() == name && Admin::Innopolis->persons[i].getSurname() == surname){
            tor = false;
            user_id = Admin::Innopolis->persons[i].getId();
            break;
        }
    }
    if(tor){
        cout<<"No such User\n";
        return;
    }
    cout<<"Room number : \n";
    cin>>room_id;
    for(int i=0;i<Admin::Innopolis->rooms_len;i++){
        if(Admin::Innopolis->rooms[i].room_id == room_id){
            Admin::Innopolis->rooms[i].addInAccessed(user_id);
            cout<<"Added\n";
            return;
        }
    }
    cout<<"No such room\n";
}
void RemoveSpecialAccess(){
    string name,surname;
    int room_id,user_id;
    cout<<"Name : \n";
    cin>>name;
    cout<<"Surname : \n";
    cin>>surname;
    bool tor = true;
    for(int i=0;i<Admin::Innopolis->persons_len;i++){
        if(Admin::Innopolis->persons[i].getName() == name && Admin::Innopolis->persons[i].getSurname() == surname){
            tor = false;
            user_id = Admin::Innopolis->persons[i].getId();
            break;
        }
    }
    if(tor){
        cout<<"No such User\n";
        return;
    }
    cout<<"Room number : \n";
    cin>>room_id;
    for(int i=0;i<Admin::Innopolis->rooms_len;i++){
        if(Admin::Innopolis->rooms[i].room_id == room_id){
            Admin::Innopolis->rooms[i].removeAccess(user_id);
            cout<<"Removed\n";
            return;
        }
    }
    cout<<"No such room\n";
}
void ChangeGroupsForLabEmployees(){
    string name,surname;
    cout<<"Name : \n";
    cin>>name;
    cout<<"Surname : \n";
    cin>>surname;
    bool tor = true;
    lab_employees* le = nullptr;
    for(int i=0;i<Admin::Innopolis->persons_len;i++){
        if(Admin::Innopolis->persons[i].getName() == name
           && Admin::Innopolis->persons[i].getSurname() == surname) {

            tor = false;
            le = (lab_employees *)&(Admin::Innopolis->persons[i]);
            break;
        }
    }
    if(tor){
        cout<<"Not in system\n";
        return;
    }
    int num_groups;
    cout<<"Number of groups : \n";
    cin>>num_groups;
    int* groups = (int*)malloc(num_groups*sizeof(int));
    for(int i=0;i<num_groups;i++){
        cout<<"Write group number ("<<i+1<<"): \n";
        cin>>groups[i];
    }
    le->setGroups(groups, num_groups);
}
void ChangeGroupForStudent(){
    string name,surname;
    cout<<"Name : \n";
    cin>>name;
    cout<<"Surname : \n";
    cin>>surname;
    bool tor = true;
    Student* user = nullptr;
    for(int i=0;i<Admin::Innopolis->persons_len;i++){
        if(Admin::Innopolis->persons[i].getName() == name
           && Admin::Innopolis->persons[i].getSurname() == surname) {

            tor = false;
            user = ((Student *)&(Admin::Innopolis->persons[i]));
            break;
        }
    }
    if(tor){
        cout<<"Not in system\n";
        return;
    }
    int groupNum;
    cout<<"Group number: \n";
    cin>>groupNum;
    user->setGroup(groupNum);
}
void ShowAllUsers(){
    Person* user;
    for(int i=0;i<Admin::Innopolis->persons_len;i++){
        user = &(Admin::Innopolis->persons[i]);
        cout<<user->getId()<<" "<<user->getName()<<" "<<user->getSurname()<<endl;
    }
}
void ShowAllRooms(){
    Room* user;
    for(int i=0;i<Admin::Innopolis->rooms_len;i++){
        user =&(Admin::Innopolis->rooms[i]);
        cout<<user->room_id<<" "<<user->getName()<<" "<<user->getAccessLevel()<<endl;
    }
}
int main() {
    init_step();
    string line = "";
    while(cin>>line) {
        if("Logout" == line||line == "Exit"||line == "exit" || line == "out"){
            return 0;
        }else if("Login" == line){
            Login();
        }else if(line == "GetStudent"){
            GetStudent();
        }else if(line == "GetAdmin"){
            GetAdmin();
        }else if(line == "GetLabEmployees"){
            GetLabEmployees();
        }else if(line == "GetProfessor"){
            GetProfessor();
        }else if(line  == "AddNewUser"){
            AddNewUser();
        }else if(line == "Exit"){
            return 0;
        }else if(line  == "AddNewRoom"){
            AddNewRoom();
        }else if(line == "CanUserEnter"){
            CanUserEnter();
        }else if(line == "AddSpecialAccess"){
            AddSpecialAccess();
        }else if(line == "RemoveSpecialAccess"){
            RemoveSpecialAccess();
        }else if(line == "ChangeGroupsForLabEmployees"){
            ChangeGroupsForLabEmployees();
        }else if(line == "ChangeGroupForStudent"){
            ChangeGroupForStudent();
        }else if(line == "ShowAllUsers"){
            ShowAllUsers();
        }else if(line == "ShowAllRooms"){
            ShowAllRooms();
        }



    }

    return 0;
}
