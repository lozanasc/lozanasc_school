/*
  Made by: Sean Christian Lozana
*/
// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
// #pragma once
#pragma once

// Dependency Imports
#include <iostream>
#include "SubjectList.hpp"
#include "TerminalClear.hpp"

using std::string;

// Comment this
class Enrollment {
public:
  // Comment this
  class Enrollee {
    int EnrollmentId;
    string FirstName, LastName, Username, Password, Course;
    bool AcceptanceStatus;
  public:

    SubjectList Subjects;

    Enrollee* Next;
    // Comment this
    Enrollee(int Id, string Fname, string Lname, string Username, string Password, string Course, bool AcceptanceStatus) {
      this->EnrollmentId = Id;
      this->FirstName = Fname;
      this->LastName = Lname;
      this->Username = Username;
      this->Password = Password;
      this->Course = Course;
      this->AcceptanceStatus = AcceptanceStatus;
      Next = NULL;
    }
    // Comment this
    int GetEnrollmentId(){
      return this->EnrollmentId;
    }
    // Comment this
    string GetFullname(){
      return this->FirstName + " " + this->LastName;
    }
    // Comment this
    string GetUsername(){
      return this->Username;
    }
    // Comment this
    string GetPassword(){
      return this->Password;
    }
    // Comment this
    string GetCourse(){
      return this->Course;
    }
    void SetStatus(bool StatusUpdate){
      this->AcceptanceStatus = StatusUpdate;
    }
    // Comment this
    string GetStatus(){
      if(this->AcceptanceStatus)
        return "Accepted";
      else
        return "Not Accepted";
    }
  };


  // Comment this
  Enrollee* Head = NULL;

  // Comment this
  void EnrollNewStudent(int Id, string Fname, string Lname, string Username, string Password, string Course){
    SubjectList Subjects;
    Enrollee* NewStudent = new Enrollee(Id, Fname, Lname, Username, Password, Course, false);
    Head == NULL ? Head = NewStudent : NewStudent->Next = Head; Head = NewStudent;
  }

  void Login(string Username, string Password){
    Enrollee* CurrentEnrollee = Head;
    while(CurrentEnrollee!=NULL){
      if(CurrentEnrollee->GetUsername() == Username && CurrentEnrollee->GetPassword() == Password){
        clear();
        bool LoginSession = true;
        // Comment this
        while(LoginSession){
        int Choice;
        std::cout<<"#=======================================#\n";
        std::cout<<"#  █▀▄ ▄▀▄ ▄▀▀ █▄█ ██▄ ▄▀▄ ▄▀▄ █▀▄ █▀▄  #\n";
        std::cout<<"#  █▄▀ █▀█ ▄██ █ █ █▄█ ▀▄▀ █▀█ █▀▄ █▄▀  #\n";
        std::cout<<"#=======================================#\n";
        std::cout<<"[Enrollee in Session: ] "<<CurrentEnrollee->GetFullname()<<"\n";
        std::cout<<"[Acceptance Status: ] "<<CurrentEnrollee->GetStatus()<< "\n";
        std::cout<<"#=======================================#\n";
        std::cout<<"[1] Subjects Options \n";
        std::cout<<"[2] End Session\n";
        std::cout<<"[CHOICE:] ";std::cin>>Choice;
        switch(Choice){
            case 1: {
              clear();
              bool SubjectSession = true;
              while(SubjectSession){
                int Choice;
                std::cout<<"#================================================================#\n";
                std::cout<<"#                        Subject Options                         #\n";
                std::cout<<"#================================================================#\n";
                std::cout<<"#        [1] Add new Subjects                                    #\n";
                std::cout<<"#        [2] Show all Subjects                                   #\n";
                std::cout<<"#        [3] Exit                                                #\n";
                std::cout<<"#================================================================#\n";
                std::cout<<" [CHOICE: ] ";std::cin>>Choice;
                switch (Choice) {
                  case 1:{
                    std::cout<<"#================================================================#\n";
                    std::cout<<"#                     Adding of Subjects                         #\n";
                    std::cout<<"#================================================================#\n";
                    int Id;
                    string SubjectName, Course;
                    std::cout<<"[Enter Subject Id : ]";std::cin>>Id;
                    std::cout<<"[Enter Subject Name : ]";std::cin>>SubjectName;
                    std::cout<<"[Enter Subject Course : ]";std::cin>>Course;
                    CurrentEnrollee->Subjects.NewSubject(Id, SubjectName, Course);
                    break;
                  }
                  case 2: {
                    clear();
                    CurrentEnrollee->Subjects.ShowAllSubject();
                    break;
                  }
                  case 3: {
                    SubjectSession = false;
                    break;
                  }
                  default:
                    SubjectSession = false;
                    break;
                }
              }
              break;
            }
            case 2: {
              LoginSession = false;
              break;
            }
            default:
              LoginSession = false;
              break;
          }
        }
      }
      else{
        clear();
        std::cout<<"Wrong username or password \n";
      }
      CurrentEnrollee = CurrentEnrollee->Next;
    }
  }

  void GetEnrolleeList(){
    Enrollee* CurrentEnrollee = Head;
    if(CurrentEnrollee == NULL)
      std::cout<<"List is Empty :C \n";
    else {
      clear();
      std::cout<<"#=======================================#\n";
      std::cout<<"#            Enrollee List              #\n";
      std::cout<<"#=======================================#\n";
      while(CurrentEnrollee != NULL){
        std::cout<<"#=======================================#\n";
        std::cout<<"Name: "<<CurrentEnrollee->GetFullname()<<"\n";
        std::cout<<"Course: "<<CurrentEnrollee->GetCourse()<<"\n";
        std::cout<<"#=======================================#\n";
        CurrentEnrollee = CurrentEnrollee->Next;
      }
      std::cout<<"#=======================================#\n";
    }

  }
  
   void ChangeEnrollmentStatus(string Username,bool Status){
     Enrollee* CurrentEnrollee = Head;
   }

};
