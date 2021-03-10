/*
  Made by: Sean Christian Lozana
  Linked List that will create, store, retrieve Courses and related Subjects
*/

// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
// #pragma once

// Dependency Imports
#include <iostream>
#include "SubjectLookup.hpp"

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

  //
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
  void DeleteCourse(int CourseId){
    Course* CurrentCourse = Head;
    Course* PrevCoursePointer = NULL;
    if(CurrentCourse == NULL){
      std::cout<<"There's nothing to delete Registrar is empty!\n";
      return;
    }
    else {
      while(CurrentCourse!=NULL && CurrentCourse->GetCourseID() != CourseId){
        // Comment this
        PrevCoursePointer = CurrentCourse;
        // Comment this
        CurrentCourse = CurrentCourse->Next;
      }
      // Comment this
      if(CurrentCourse == NULL)
        std::cout<<"There's nothing to delete Registrar is empty!\n";
      // Comment this
      PrevCoursePointer->Next = CurrentCourse->Next;
      // Comment this
      delete CurrentCourse;
    }

  }
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
    // Comment this
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
        std::cout<<"["<<CourseCount<<"] "<<CurrentCourse->GetCourseName()<<"\n";
        CurrentCourse = CurrentCourse->Next;
        CourseCount++;
      }
      std::cout<<"#=======================================#\n";
    }
  }
};
