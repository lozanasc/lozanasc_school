/*
  Made by: Sean Christian Lozana
*/

// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
#pragma once

// Dependency Imports
#include <iostream>
#include "SubjectList.hpp"
#include "TerminalClear.hpp"

using std::string;

/*
  This class is responsible for storing Enrollee Information
  and methods for Adding Subject and Authentication
*/
class Enrollment {
public:
  /*
    Class for Enrollee information that contains the ff:
    * Id
    * Name -> First, Last, Username
    * Password
    * Course
    * AcceptanceStatus
  */
  class Enrollee {

    int EnrollmentId;
    string FirstName, LastName, Username, Password, Course;
    bool AcceptanceStatus;

  public:

    // SubjectList that is only exclusive to the Enrollee scope
    SubjectList Subjects;
    // Pointer that will point to the Next
    Enrollee* Next;

    /*
      Constructor responsible for initializing a new Enrollee to the List

      @params {int} Id for Identification
      @params {string} Fname First name
      @params {string} Lname Last name
      @params {string} Username for Identification and Authentication
      @params {string} Password for Authentication
      @params {string} Course for Student course
      @params {bool} AcceptanceStatus for Enrollment status that is decided by the Admin

    */
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

    // Returns the Enrollee Id
    int GetEnrollmentId(){
      return this->EnrollmentId;
    }

    // Returns the enrollee fullname by concatenating the First name and Last name
    string GetFullname(){
      return this->FirstName + " " + this->LastName;
    }

    // Returns the enrollee username identification and authentication
    string GetUsername(){
      return this->Username;
    }

    // Returns enrollee password for authentication
    string GetPassword(){
      return this->Password;
    }

    // Returns the enrollee's chosen course
    string GetCourse(){
      return this->Course;
    }

    // Setter function that sets the enrollee's acceptance status
    void SetStatus(bool StatusUpdate){
      this->AcceptanceStatus = StatusUpdate;
    }

    /*
      Getter function that is based on the AcceptanceStatus of the Enrollee that will return a string
      depending on the state of the Enrollee's Acceptance Status
    */
    string GetStatus(){
      // If the AcceptanceStatus is true, will return the string "Accepted"
      if(this->AcceptanceStatus)
        return "Accepted";
      // Else or if the Enrollee's AcceptanceStatus is false, will return "Not Accepted"
      else
        return "Not Accepted";
    }

  };


  // Reference for the Head node that is set to NULL
  Enrollee* Head = NULL;

  /*

    Function that is responsible for Adding a new Student to the Enrollment List

    @params {integer} Id for Identification
    @params {string} Fname for First name
    @params {string} Lname for Last name
    @params {string} Username for Identification and Authentication
    @params {string} Password for Authentication
    @params {string} Course for Enrollee's choice of Program to study

  */
  void EnrollNewStudent(int Id, string Fname, string Lname, string Username, string Password, string Course){
    SubjectList Subjects;
    Enrollee* NewStudent = new Enrollee(Id, Fname, Lname, Username, Password, Course, false);
    Head == NULL ? Head = NewStudent : NewStudent->Next = Head; Head = NewStudent;
  }

  /*

    Function that is responsible for Authenticating Enrollee's
    @params {string} Username for Identification and Authentication
    @params {string} Password for Authentication

  */
  void Login(string Username, string Password){

    // Referencing the temp node using the Head node
    Enrollee* CurrentEnrollee = Head;

    // Loop that traverses the entire List
    while(CurrentEnrollee!=NULL){

      /*
        Logic for Enrollee Authentication
        Checks if the Current node pointed matches the arguments with the current node's Username and Password
      */
      if(CurrentEnrollee->GetUsername() == Username && CurrentEnrollee->GetPassword() == Password){
        clear();
        // Enrollee Login Session Loop
        // Boolean variable Login session that controls the Loop
        bool LoginSession = true;
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
            /*
              This case is responsible for Enrollee's access to their SubjectList
              Enrollee's can do the ff:
              * Add new Subjects that adds new subjects to the SubjectList
              * Show all Subjects, outputs all the subjects in the SubjectList
              * Exit that breaks out of the LoginSession loop
            */
            case 1: {
              clear();
              // Boolean variable that controls the SubjectSession loop
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
                  /*
                    This case is responsible for Adding new Subject into the List
                  */
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
                  /*
                    This case is responsible for outputting all Subjects in the SubjectList
                  */
                  case 2: {
                    clear();
                    CurrentEnrollee->Subjects.ShowAllSubject();
                    break;
                  }
                  /*
                    This case is responsible for terminating the SubjectSession loop
                  */
                  case 3: {
                    SubjectSession = false;
                    break;
                  }
                  /*
                    If the input is invalid this case is triggered and will terminate the SubjectSession loop
                  */
                  default:
                    SubjectSession = false;
                    break;
                }
              }
              break;
            }
            /*
              This case is responsible for terminating the LoginSession loop
            */
            case 2: {
              LoginSession = false;
              break;
            }
            /*
              If the input is invalid this case is triggered and will terminate the LoginSession loop
            */
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
      // CurrentEnrollee pointer will get the next memory address of the next node
      CurrentEnrollee = CurrentEnrollee->Next;
    }
  }

  /*
    Function that outputs all the Enrollee's in the List
  */
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
        std::cout<<"Username: "<<CurrentEnrollee->GetUsername()<<"\n";
        std::cout<<"Course: "<<CurrentEnrollee->GetCourse()<<"\n";
        std::cout<<"#=======================================#\n";
        CurrentEnrollee = CurrentEnrollee->Next;
      }
      std::cout<<"#=======================================#\n";
    }

  }

  /*
    This function is responsible for changing enrollment status of the Student
    How it does is it traverses the entire list and searches for the Username parameter to
    match the Node's Username.
  */
 void ChangeEnrollmentStatus(string Username, bool StatusChange){
   Enrollee* CurrentEnrollee = Head;

   if(CurrentEnrollee == NULL)
    std::cout<<"List is Empty... \n";

    else {

      while(CurrentEnrollee != NULL){

        if(CurrentEnrollee->GetUsername() == Username){
          clear();
          CurrentEnrollee->Subjects.ShowAllSubject();
          std::cout<<"#====================================================#\n";
          std::cout<<"# Student found, Enrollment status has been updated  #\n";
          std::cout<<"#====================================================#\n";
          CurrentEnrollee->SetStatus(StatusChange);
        }

        CurrentEnrollee = CurrentEnrollee->Next;
    }
  }
 }

};
