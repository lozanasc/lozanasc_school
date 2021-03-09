/*
  Made by: Sean Christian Lozana
*/
#include <iostream>

// Comment this
class SubjectList {
public:
  // Comment this
  class StudentSubject{
    int SubjectId;
    string SubjectName;
  public:
    StudentSubject* Next;
    // Comment this
    StudentSubject(int Id, string Name){
      this->SubjectId = Id;
      this->SubjectName = Name;
    }
    // Comment this
    int GetSubjectId(){
      return this->SubjectId;
    }
    // Comment this
    string GetSubjectName(){
      return this->SubjectName;
    }
  };
  // Comment this
  StudentSubject* Head = NULL;

  // Comment this
  void NewSubject(int Id, string Name){
    // Comment this
    StudentSubject* NewSubject = new StudentSubject(Id, Name);
    // Comment this
    Head == NULL ? Head = NewSubject : NewSubject->Next = Head; Head = NewSubject;
  }


};
