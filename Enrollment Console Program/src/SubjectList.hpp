/*
  Made by: Sean Christian Lozana
*/
#include <iostream>

// Comment here
class SubjectList {
public:
  // Comment here
  class StudentSubject{
    int SubjectId;
    string SubjectName;
  public:
    StudentSubject* Next;
    // Comment here
    StudentSubject(int Id, string Name){
      this->SubjectId = Id;
      this->SubjectName = Name;
    }
    // Comment here
    int GetSubjectId(){
      return this->SubjectId;
    }
    // Comment here
    string GetSubjectName(){
      return this->SubjectName;
    }
  };
};
