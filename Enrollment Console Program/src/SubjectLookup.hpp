/*
  Made by: Sean Christian Lozana

*/

#pragma once

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
  string SubjectName, AssociatedCourse;
  bool IsMajor;
    // Comment this
  public:
    Subject* Next;
    // Comment this
    Subject(string Course, int SubjectId, string SubjectName, bool Major){
      this->SubjectId = SubjectId;
      this->SubjectName = SubjectName;
      this->IsMajor = Major;
      this->AssociatedCourse = Course;
      Next = NULL;
    }
    // Comment this
    void SetAssociatedCourse(string CourseName){
      this->AssociatedCourse = CourseName;
    }
    // Comment this
    string GetAssociatedCourse(){
      return this->AssociatedCourse;
    }

    // Comment this
    int GetSubjectId(){
      return this->SubjectId;
    }
    // Comment this
    string GetSubjectName(){
      return this->SubjectName;
    }
    bool GetMajorStatus(){
      return this->IsMajor;
    }
  };

  // Comment this
  Subject* Head = NULL;

  // Comment this
  void NewSubject(string Course, int SubjectId, string SubjectName, bool IsMajor){
    // Comment this
    Subject* NewSubject = new Subject(Course, SubjectId, SubjectName, IsMajor);
    // Comment this
    Head == NULL ? Head = NewSubject : NewSubject->Next = Head; Head = NewSubject;
  }

  void ShowSubjectList(){
    Subject* CurrentSubject = Head;
    if(CurrentSubject == NULL)
      std::cout<<"No subject in the List\n";
    while(CurrentSubject!=NULL){
      std::cout<<"Subject Information: \n";
      std::cout<<"Subject Id: "<<CurrentSubject->GetSubjectId()<<"\n";
      std::cout<<"Subject Name: "<<CurrentSubject->GetSubjectName()<<"\n";
      CurrentSubject = CurrentSubject->Next;
    }
  }

  // Comment this
  int SearchSubjectByPosition(int SubjectId){
    int SubjectCount = 0;
    Subject* CurrentSubject = Head;
    if(CurrentSubject == NULL)
      std::cout<<"No subjects in the list \n";

    while (CurrentSubject != NULL) {
      if (CurrentSubject->GetSubjectId() == SubjectId)
        return SubjectCount;
      SubjectCount++;
      CurrentSubject = CurrentSubject->Next;
    }
    return SubjectCount;
  }

  void DeleteSubject(int Position){

    // List is Empty
    if (Head == NULL)
      return;

    // Temp head node
    Subject* PrevSubjectPointer = Head;

    // If the Course is at the Head node
    if(Position == 0){
        Head = PrevSubjectPointer->Next;
        free(PrevSubjectPointer);
        return;
    }

    // Loops over the List and finds the previous node of the node to be deleted
    for (int i=0; PrevSubjectPointer != NULL && i < Position - 1; i++) {
      PrevSubjectPointer = PrevSubjectPointer->Next;
    }

    // Checks if the Position does not go out of bounds
    if (PrevSubjectPointer == NULL || PrevSubjectPointer->Next == NULL)
      return;

    // The Next pointer of PrevCoursePointer is the node to be removed
    // Will store the pointer to the next of node to be deleted
    Subject* Next = PrevSubjectPointer->Next->Next;

    // Unlinks the Node from the List
    free(PrevSubjectPointer->Next);

    PrevSubjectPointer->Next = Next;
  }

};
