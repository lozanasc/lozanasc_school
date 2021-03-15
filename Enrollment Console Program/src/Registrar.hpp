/*
  Made by: Sean Christian Lozana
  Linked List that will create, store, retrieve Courses and related Subjects
*/

// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
// #pragma once

// Dependency Imports
#include <iostream>
#include "SubjectLookup.hpp"
#include "TerminalClear.hpp"

using std::string;

// Comment this
class Registrar {
  public:
  class Course {
    int CourseId;
    string CourseName;
  public:
    Course* Next;
    // Constructor
    Course(int CourseId, string CourseName){
      this->CourseId = CourseId;
      this->CourseName = CourseName;
      Next = NULL;
    }
    // Comment this
    int GetCourseID(){
      return this->CourseId;
    }
    // Comment this
    string GetCourseName(){
      return this->CourseName;
    }

  };

  // Comment this
  SubjectLookup SubjectList;
  // Initializes the Head pointer, pointing to null
  Course* Head = NULL;

  // Comment this
  void CreateCourse(int CourseId, string CourseName){
    // Comment this
    Course* NewCourse = new Course(CourseId, CourseName);
    // Comment this
    Head == NULL ? Head = NewCourse : NewCourse->Next = Head; Head = NewCourse;
  }

  // Comment this
  int SearchByPosition(int CourseId){
    int CoursePosition = 0 ;
    Course* CurrentCourse = Head;
    // List is Empty
    if(CurrentCourse == NULL)
      std::cout<<"There's nothing to delete \n";

    while(CurrentCourse != NULL){
      if(CurrentCourse->GetCourseID() == CourseId)
        return CoursePosition;
      CoursePosition++;
      CurrentCourse = CurrentCourse->Next;
    }

    return CoursePosition;
  }

  // Comment this
  void DeleteCourse(int Position){

    // List is Empty
    if (Head == NULL)
      return;

    // Temp head node
    Course* PrevCoursePointer = Head;

    // If the Course is at the Head node
    if(Position == 0){
        Head = PrevCoursePointer->Next;
        free(PrevCoursePointer);
        return;
    }

    // Loops over the List and finds the previous node of the node to be deleted
    for (int i=0; PrevCoursePointer != NULL && i < Position - 1; i++) {
      PrevCoursePointer = PrevCoursePointer->Next;
    }

    // Checks if the Position does not go out of bounds
    if (PrevCoursePointer == NULL || PrevCoursePointer->Next == NULL)
      return;

    // The Next pointer of PrevCoursePointer is the node to be removed
    // Will store the pointer to the next of node to be deleted
    Course* Next = PrevCoursePointer->Next->Next;

    // Unlinks the Node from the List
    free(PrevCoursePointer->Next);

    PrevCoursePointer->Next = Next;
  }

  // Comment this
  bool CheckCourseAvailability(string CourseName){
    Course* CurrentCourse = Head;
    // Initial State
    bool IsFound = false;
    if(CurrentCourse == NULL)
      IsFound = false;
    else {
      while(CurrentCourse!=NULL){
        if(CurrentCourse->GetCourseName() == CourseName)
          IsFound = true;
        CurrentCourse = CurrentCourse->Next;
      }
    }
    return IsFound;
  }

  // Comment this
  void GetCourseList(){
    int CourseCount = 0;
    Course* CurrentCourse = Head;
    // Comment this
    if(CurrentCourse == NULL){
      std::cout<<"No course is available at the moment\n";
    }
    else {
      // Comment this
      std::cout<<"#=======================================#\n";
      std::cout<<"#            Courses Offered:           #\n";
      std::cout<<"#=======================================#\n";
      while(CurrentCourse != NULL){
        std::cout<<"#=======================================#\n";
        std::cout<<"Position: ["<<CourseCount<<"] "<<CurrentCourse->GetCourseName()<<"\n[Course ID: ] "<<CurrentCourse->GetCourseID()<<"\n";
        CurrentCourse = CurrentCourse->Next;
        CourseCount++;
        std::cout<<"#=======================================#\n";
      }
      std::cout<<"#=======================================#\n";
    }
    return;
  }

  // Comment this
  void AddSubject(string Course, int SubjectId, string SubjectName, bool IsMajor){
    SubjectList.NewSubject(Course, SubjectId, SubjectName, IsMajor);
  }

  void DeleteSubject(){
    SubjectList.DeleteSubject();
  }

  // Comment this
  void ShowSubjects(int SubjectId){
    SubjectList.ShowSubjectList(SubjectList.SearchSubjectByPosition(SubjectId));
  }

};
