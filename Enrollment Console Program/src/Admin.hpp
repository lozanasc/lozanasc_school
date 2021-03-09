/*
  Made by: Sean Christian Lozana
*/

// Dependency Imports
#include <iostream>
#include "Registrar.hpp"
#include "SubjectLookup.hpp"

// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
#pragma once

// Comment this
class Admin {
public:
  class User {
    string Name, Password;
    Registrar CourseList;
  public:
    User* Next;
    // Comment this
    User(string Name, string Password, Registrar UserCourseList){
      this->Name = Name;
      this->Password = Password;
      this->CourseList = UserCourseList;
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
  SubjectLookup CourseSubjectList;
  // Comment this
  class User* Head = NULL;
  // Comment this
  void CreateAccount(string Username, string Password, Registrar UserCourseList){
    // Comment this
    User* NewAccount = new User(Username, Password, UserCourseList);
    // Comment this
    Head == NULL ? Head = NewAccount : NewAccount->Next = Head; Head = NewAccount;
  }
  // Comment this
  bool AccountCheck(string Username){
    // Comment this
    User* CurrentAccount = Head;
    // Comment this
    // Doesn't take into account 1st time Registrations
    // if(CurrentAccount == NULL){
    //   std::cout<<"No account is registered.";
    //   return false;
    // }
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
        std::cout<<"[1] Course Options\n";
        std::cout<<"[2] Show Course List\n";
        std::cout<<"[3] End Session\n";
        std::cout<<"[CHOICE:] ";std::cin>>Choice;
        switch(Choice){
          case 1: {
            bool Session = true;
            while(Session){
              int Choice;
              std::cout<<"#=======================================#\n";
              std::cout<<"#          Course Options               #\n";
              std::cout<<"#          [1] Add new Course           #\n";
              std::cout<<"#          [2] Edit Course              #\n";
              std::cout<<"#          [3] Exit                     #\n";
              std::cout<<"#=======================================#\n";
              std::cout<<"[CHOICE:] ";std::cin>>Choice;
              switch (Choice) {
                case 1:{
                  int Choice, CourseId;
                  string CourseName;
                  bool Session = true;
                  std::cout<<"#=======================================#\n";
                  std::cout<<"Enter new Course Id: ";std::cin>>CourseId;
                  std::cout<<"Enter new Course Name:";std::cin>>CourseName;
                  AccountToVerify->GetRegistrar().CreateCourse(CourseId, CourseName, CourseSubjectList);
                  while(Session){
                    std::cout<<"#=======================================#\n";
                    std::cout<<"#          Subject Options              #\n";
                    std::cout<<"#          [1] Add new Subject          #\n";
                    std::cout<<"#          [2] Exit                     #\n";
                    std::cout<<"#=======================================#\n";
                    std::cout<<" Editing Course: "<<CourseName<<"\n";
                    std::cout<<"[CHOICE:] ";std::cin>>Choice;
                    switch(Choice){
                      case 1: {
                        int Id;
                        string Name;
                        std::cout<<"Enter subject code: ";std::cin>>Id;
                        std::cout<<"\n[USE DASH FOR SPACE]\nEnter subject name: ";std::cin>>Name;
                        AccountToVerify->GetRegistrar().InsertSubject(CourseId, Id, Name);
                        break;
                      }
                      case 2: {
                        Session = false;
                        break;
                      }
                      default:
                        std::cout<<"Wrong input\n";
                        break;
                    }
                  }
                  break;
                }
                case 2: {
                  std::cout<<"Wrong input\n";
                  break;
                }
                case 3: {
                  Session = false;
                  break;
                }
                default:
                  Session = false;
                  break;
              }
            }
            break;
          }
          case 2: {
            AccountToVerify->GetRegistrar().CourseAvailable();
            break;
          }
          case 3: {
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
