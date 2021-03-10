/*
  Made by: Sean Christian Lozana
*/
// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
// #pragma once

// Dependency Imports
#include <iostream>

#pragma once

using std::string;

// Comment this
class Enrollment {
public:
  // Comment this
  class Enrollee{
    int EnrollmentId;
    string FirstName, LastName, Username, Password, Course;
  public:
    Enrollee* Next;
    // Comment this
    Enrollee(int Id, string Fname, string Lname, string Username, string Password, string Course){
      this->EnrollmentId = Id;
      this->FirstName = Fname;
      this->LastName = Lname;
      this->Username = Username;
      this->Password = Password;
      this->Course = Course;
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
    string GetUsername(){
      return this->Username;
    }
    string GetPassword(){
      return this->Password;
    }
    string GetCourse(){
      return this->Course;
    }

  };

  // Comment this
  Enrollee* Head = NULL;

  // Comment this
  void EnrollNewStudent(int Id, string Fname, string Lname, string Username, string Password, string Course){
    Enrollee* NewStudent = new Enrollee(Id, Fname, Lname, Username, Password, Course);
    Head == NULL ? Head = NewStudent : NewStudent->Next = Head; Head = NewStudent;
  }

  void GetEnrolleeList(){
    Enrollee* CurrentEnrollee = Head;

    if(CurrentEnrollee == NULL)
      std::cout<<"List is Empty :C \n";
    else {
      std::cout<<"#=======================================#\n";
      std::cout<<"#            Enrollee List              #\n";
      std::cout<<"#=======================================#\n";
      while(CurrentEnrollee != NULL){
        std::cout<<" "<<CurrentEnrollee->GetFullname()<<"\n";
        CurrentEnrollee = CurrentEnrollee->Next;
      }
      std::cout<<"#=======================================#\n";
    }

  }

};
