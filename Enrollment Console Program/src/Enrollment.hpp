/*
  Made by: Sean Christian Lozana
*/
// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
// #pragma once

// Dependency Imports
#include <iostream>
#include "Registrar.hpp"

// Comment this
class Enrollment {
public:
  // Comment this
  class Enroll{
    int EnrollmentId;
    string FirstName, LastName;
  public:
    Enroll* Next;
    Enroll(int Id, string Fname, string Lname){
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

};
