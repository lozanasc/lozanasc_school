/*
  Made by: Sean Christian Lozana
*/
// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
// #pragma once

// Dependency Imports
#include <iostream>

using std::string;

// Comment this
class Enrollment {
public:
  // Comment this
  class Enrollee{
    int EnrollmentId;
    string FirstName, LastName, Course;
  public:
    Enrollee* Next;
    // Comment this
    Enrollee(int Id, string Fname, string Lname, string Course){
      this->EnrollmentId = Id;
      this->FirstName = Fname;
      this->LastName = Lname;
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

    string GetCourse(){
      return this->Course;
    }

  };

  // Comment this
  Enrollee* Head = NULL;

  // Comment this
  void EnrollNewStudent(int Id, string Fname, string Lname, string Course){
    Enrollee* NewStudent = new Enrollee(Id, Fname, Lname, Course);
    Head == NULL ? Head = NewStudent : NewStudent->Next = Head; Head = NewStudent;
  }

};
