/*
  Made by: Sean Christian Lozana
*/

#include <iostream>
#include "Registrar.hpp"

using std::string;

// Comment this
class Admin {
public:
  class User {
    string Name, Password;
    Registrar CourseList;
  public:
    User* Next;
    // Comment this
    User(string Name, string Password){
      this->Name = Name;
      this->Password = Password;
    }
    // Comment this
    string GetName(){
      return this->Name;
    }
    // Comment this
    string GetPassword(){
      return this->Password;
    }
    // Comment this
    Registrar GetRegistrar(){
      return this->CourseList;
    }
  };
  // Comment this
  class User* Head = NULL;
  // Comment this
  void CreateAccount(string Username, string Password){
    User* NewAccount = new User(Username, Password);
    Head == NULL ? Head = NewAccount : NewAccount->Next = Head; Head = NewAccount;
  }
  // Comment this
  bool AccountCheck(string Username){
    // Comment this
    User* CurrentAccount = Head;
    // Comment this
    if(CurrentAccount == NULL){
      std::cout<<"No account is registered.";
      return false;
    }
    // Comment this
    while(CurrentAccount != NULL){
      if(CurrentAccount->GetName() == Username){
        return false;
      }
      CurrentAccount = CurrentAccount->Next;
    }
    return true;
  }
  // Comment this
  void Login(string Username, string Password){
    // Comment this
    User* AccountToVerify = Head;
    // Comment this
    if(AccountToVerify == NULL)
      std::cout<<"Such account exist in the database\n";
    // Comment this
    while(AccountToVerify != NULL){
      // Comment this
      if(AccountToVerify->GetName() == Username && AccountToVerify->GetPassword() == Password){
        bool Session = true;
        // Comment this
        while(Session){
        int Choice;
        std::cout<<"#=======================================#\n";
        std::cout<<"#  █▀▄ ▄▀▄ ▄▀▀ █▄█ ██▄ ▄▀▄ ▄▀▄ █▀▄ █▀▄  #\n";
        std::cout<<"#  █▄▀ █▀█ ▄██ █ █ █▄█ ▀▄▀ █▀█ █▀▄ █▄▀  #\n";
        std::cout<<"#=======================================#\n";
        std::cout<<"[User in Session:] "<<AccountToVerify->GetName()<<"\n";
        std::cout<<"#=======================================#\n";
        std::cout<<"[1] New Course\n";
        std::cout<<"[2] End Session\n";
        std::cout<<"[CHOICE:] ";std::cin>>Choice;
        switch(Choice){
          case 1: {
            int CourseId;
            string CourseName;
            std::cout<<"#=======================================#\n";
            std::cout<<"Enter new Course Id: ";std::cin>>CourseId;
            std::cout<<"Enter new Course Name:";std::cin>>CourseName;
            AccountToVerify->GetRegistrar().CreateCourse(CourseId, CourseName);
            break;
          }
          case 2: {
            Session = false;
            break;
          }
          default:
            Session = false;
            break;
        }
        std::cout<<"#=======================================#\n";

      }
      }
      AccountToVerify = AccountToVerify->Next;
    }
  }
};
