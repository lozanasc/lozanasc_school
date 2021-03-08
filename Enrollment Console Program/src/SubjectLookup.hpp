/*
  Made by: Sean Christian Lozana
*/

// Dependency Imports
#include <iostream>

using std::string;

// Comment this
class SubjectLookup {
public:
  class Subject {
    // Comment this
  int SubjectId;
    // Comment this
  string SubjectName;
    // Comment this
  public:
    Subject* Next;
    // Comment this
    Subject(int SubjectId, string SubjectName){
      this->SubjectId = SubjectId;
      this->SubjectName = SubjectName;
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
  Subject* Head = NULL;

  // Comment this
  void NewSubject(int SubjectId, string SubjectName){
    // Comment this
    Subject* NewSubject = new Subject(SubjectId, SubjectName);
    // Comment this
    Head == NULL ? Head = NewSubject : NewSubject->Next = Head; Head = NewSubject;
  }
  // Comment this
  void DeleteSubject(int SubjectId){
    // Comment this
    Subject* CurrentSubject = Head;
    // Comment this
    Subject* PrevSubjectPointer = NULL;
    // Checks if the Subject Lookup is empty
    if(CurrentSubject == NULL){
      std::cout<<"No such subject found in the List\n";
      return;
    }
    else {
      // Comment this
      while(CurrentSubject != NULL && CurrentSubject->GetSubjectId() != SubjectId){
        // Comment this
        PrevSubjectPointer = CurrentSubject;
        // Comment this
        CurrentSubject = CurrentSubject->Next;
      }
      // Comment this
      if(CurrentSubject==NULL)
        std::cout<<"Such subject does not exist";
      // Comment this
      PrevSubjectPointer->Next = CurrentSubject->Next;
      // Comment this
      delete CurrentSubject;
    }
  }
};
