/*
  Made by: Sean Christian Lozana
*/
// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
// #pragma once

// Dependency Imports
#include <iostream>
#include "Registrar.hpp"
#include "SubjectList.hpp"

// Comment this
class Enrollment {
public:
  // Comment this
  class Enrollee{
    int EnrollmentId;
    string FirstName, LastName;
    SubjectList SubjectLoad;
  public:
    Enrollee* Next;
    Enrollee(int Id, string Fname, string Lname){
      this->EnrollmentId = Id;
      this->FirstName = Fname;
      this->LastName = Lname;
    }
    int GetEnrollmentId(){
      return this->EnrollmentId;
    }
    string GetFullname(){
      return this->FirstName + " " + this->LastName;
    }
  };

  Enrollee* Head = NULL;

  void EnrollNewStudent(int Id, string Fname, string Lname){
    Enrollee* NewStudent = new Enrollee(Id, Fname, Lname);
    Head == NULL ? Head = NewStudent : NewStudent->Next = Head; Head = NewStudent;
  }

  // void AddSubject(string SubjectName){
  //
  // }


};
