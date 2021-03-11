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
        clear();
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
            clear();
            bool CourseSession = true;
            while(CourseSession){
              int Choice;
              std::cout<<"#================================================================#\n";
              std::cout<<"#                        Course Options                          #\n";
              std::cout<<"#================================================================#\n";
              std::cout<<"#        [1] Add new Course                                      #\n";
              std::cout<<"#        [2] Show all Courses                                    #\n";
              std::cout<<"#        [3] Remove Course                                       #\n";
              std::cout<<"#        [4] Exit                                                #\n";
              std::cout<<"#================================================================#\n";
              std::cout<<"[CHOICE: ] ";std::cin>>Choice;
              switch (Choice) {
                case 1:{
                  clear();
                  int CourseId;
                  string CourseName;
                  std::cout<<"#================================================================#\n";
                  std::cout<<"#                        Adding of Course                        #\n";
                  std::cout<<"#================================================================#\n";
                  std::cout<<"[Enter Course Id: ] ";std::cin>>CourseId;
                  std::cout<<"[Enter Course Name: ] ";std::cin>>CourseName;
                  CourseList.CreateCourse(CourseId, CourseName);
                  break;
                }
                case 2:{
                  clear();
                  CourseList.GetCourseList();
                  break;
                }
                case 3: {
                  int CourseToDelete;
                  std::cout<<"[Course Available: ]\n";
                  CourseList.GetCourseList();
                  std::cout<<"[Enter Course ID: ]";std::cin>>CourseToDelete;
                  CourseList.DeleteCourse(CourseToDelete);
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
            clear();
            bool SubjectSession = true;
            while(SubjectSession){
              int Choice;
              std::cout<<"#================================================================#\n";
              std::cout<<"#                       Subject Options                          #\n";
              std::cout<<"#================================================================#\n";
              std::cout<<"#        [1] Add new Subject                                     #\n";
              std::cout<<"#        [2] Show all Subject                                    #\n";
              std::cout<<"#        [3] Remove Subject                                      #\n";
              std::cout<<"#        [4] Exit                                                #\n";
              std::cout<<"#================================================================#\n";
              std::cout<<"[CHOICE: ] ";std::cin>>Choice;
              switch(Choice){
                case 1: {
                  clear();
                  int SubjectId;
                  bool IsMajor;
                  string SubjectName, Course;
                  CourseList.GetCourseList();
                  std::cout<<"#================================================================#\n";
                  std::cout<<"#                        Adding of Subject                       #\n";
                  std::cout<<"#================================================================#\n";
                  std::cout<<"[Choose from the Courses available above] \n";
                  std::cout<<"[Enter Course: ] ";std::cin>>Course;
                  if(CourseList.CheckCourseAvailability(Course)){
                    std::cout<<"[Enter Subject Id: ] ";std::cin>>SubjectId;
                    std::cout<<"[Enter Subject Name: ] ";std::cin>>SubjectName;
                    std::cout<<"[Is the Subject a Major? ( [1] for true / [0] for false ): ] ";std::cin>>IsMajor;
                    CourseList.AddSubject(Course, SubjectId, SubjectName, IsMajor);
                    break;
                  }
                  else {
                    std::cout<<"[Course not available] \n";
                  }
                  break;
                }
                case 2: {
                  clear();
                  CourseList.ShowSubjects();
                  break;
                }
                case 3: {
                  break;
                }
                case 4: {
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
          case 3: {
            clear();
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
      else
        std::cout<<"Wrong username or password\n";
      AccountToVerify = AccountToVerify->Next;
      }
    }
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
  void EnrolleeLogin(string Username, string Password){
      Enroll.Login(Username, Password);
    }
};
