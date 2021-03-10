/*
  Made by: Sean Christian Lozana
*/

// Dependency Imports
#include <iostream>
#include "Registrar.hpp"
#include "Enrollment.hpp"
// Comment this
class Admin {
public:
  class User {
    string Name, Password;
  public:
    User* Next;
    // Comment this
    User(string Name, string Password){
      this->Name = Name;
      this->Password = Password;
      Next = NULL;
    }
    // Comment this
    string GetName(){
      return this->Name;
    }
    // Comment this
    string GetPassword(){
      return this->Password;
    }
  };

  // Comment this
  Registrar CourseList;
  Enrollment Enroll;

  User* Head = NULL;
  // Comment this
  void CreateAccount(string Username, string Password){
    // Comment this
    User* NewAccount = new User(Username, Password);
    // Comment this
    Head == NULL ? Head = NewAccount : NewAccount->Next = Head; Head = NewAccount;
  }
  // Comment this
  bool AccountCheck(string Username){
    // Comment this
    User* CurrentAccount = Head;
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
      std::cout<<"Such account doesn't exist in the database\n";
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
        std::cout<<"[User in Session: ] "<<AccountToVerify->GetName()<<"\n";
        std::cout<<"#=======================================#\n";
        std::cout<<"[1] Course Options\n";
        std::cout<<"[2] Subjects Options \n";
        std::cout<<"[3] Show Enrollee List\n";
        std::cout<<"[4] End Session\n";
        std::cout<<"[CHOICE:] ";std::cin>>Choice;
        switch(Choice){
          case 1: {
            bool CourseSession = true;
            while(CourseSession){
              int Choice;
              std::cout<<"#================================================================#\n";
              std::cout<<"#                        Course Options                          #\n";
              std::cout<<"#================================================================#\n";
              std::cout<<"#        [1] Add new Course                                      #\n";
              std::cout<<"#        [2] Show all Courses                                    #\n";
              std::cout<<"#        [3] Exit                                                #\n";
              std::cout<<"#================================================================#\n";
              std::cout<<"[CHOICE: ] ";std::cin>>Choice;
              switch (Choice) {
                case 1:{
                  int CourseId;
                  string CourseName;
                  std::cout<<"[Enter Course Id: ] ";std::cin>>CourseId;
                  std::cout<<"[Enter Course Name: ] ";std::cin>>CourseName;
                  CourseList.CreateCourse(CourseId, CourseName);
                  break;
                }
                case 2:{
                  CourseList.GetCourseList();
                  break;
                }
                case 3: {
                  CourseSession = false;
                  break;
                }
                default:
                  CourseSession = false;
                  break;
              }
            }
            break;
          }
          case 2: {
            break;
          }
          case 3: {
            Enroll.GetEnrolleeList();
            break;
          }
          case 4: {
            Session = false;
            break;
          }
          default:
            std::cout<<"Wrong input \n";
            break;
        }
        }
      }
      AccountToVerify = AccountToVerify->Next;
    }
  }
    // Dog water code
    bool CheckCourseAvailability(string CourseName){
      return CourseList.CheckCourseAvailability(CourseName);
    }
    void ShowCourseList(){
      CourseList.GetCourseList();
    }
    void EnrollmentForm(int Id, string Fname, string Lname, string Username, string Password, string Course){
      if(CheckCourseAvailability(Course))
        Enroll.EnrollNewStudent(Id, Fname, Lname, Username, Password, Course);
      else
        std::cout<<"Sorry course not yet available :C \n";

    }
};
