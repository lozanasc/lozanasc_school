/*
  Made by: Sean Christian Lozana
  Linked List that will create, store, retrieve Courses and related Subjects
*/

// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
#pragma once

// Dependency Imports
#include <iostream>

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
    Course* CurrenctCourse = Head;
    Course* PrevCoursePointer = NULL;
    if(CurrentCourse == NULL){
      std::cout<<"There's nothing to delete Registrar is empty!\n";
      return;
    }
    else {
      while(CurrentCourse!=NULL && CurrentCourse->GetCourseID() != CourseId){
        // Comment this
        PrevCoursePointer = CurrenctCourse;
        // Comment this
        CurrentCourse = CurrenctCourse->Next;
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
  // Comment this
  void CourseAvailable(){
    // Comment this
    int CourseCount = 0;
    Course* CurrentCourse = Head;
    // Comment this
    if(CurrentCourse == NULL){
      std::cout<<"No course is available at the moment\n";
    }
    // Comment this
    while(CurrentCourse != NULL){
      std::cout<<"#=======================================#\n";
      std::cout<<"#            Courses Offered:           #\n";
      std::cout<<"#=======================================#\n";
      std::cout<<"["<<CourseCount<<"] "<<CurrentCourse->GetCourseName()<<"\n";
      std::cout<<"#=======================================#\n";
      CurrentCourse = CurrentCourse->Next;
      CourseCount++;
    }
  }
};
