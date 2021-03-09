/*
  Made by: Sean Christian Lozana
  Linked List that will create, store, retrieve Courses and related Subjects
  Personally I think Tree or a Hashmap is a much better Data Structure to use for this particular problem
*/

// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
#pragma once

// Dependency Imports
#include <iostream>
#include "SubjectLookup.hpp"

// Comment this
class Registrar {
  public:
  class Course {
    int CourseId;
    string CourseName;
    // Comment this
    SubjectLookup Subjects;
  public:
    Course* Next;
    // Constructor
    Course(int CourseId, string CourseName, SubjectLookup CourseSubjects){
      this->CourseId = CourseId;
      this->CourseName = CourseName;
      this->Subjects = CourseSubjects;
    }
    // Comment this
    int GetCourseID(){
      return this->CourseId;
    }
    // Comment this
    string GetCourseName(){
      return this->CourseName;
    }

    // Comment this
    SubjectLookup GetSubjects(){
      return this->Subjects;
    }
  };
  // Initializes the Head pointer, pointing to null
  Course* Head = NULL;

  // Comment this
  void CreateCourse(int CourseId, string CourseName, SubjectLookup CourseSubjects){
    // Comment this
    Course* NewCourse = new Course(CourseId, CourseName, CourseSubjects);
    // Comment this
    Head == NULL ? Head = NewCourse : NewCourse->Next = Head; Head = NewCourse;
  }

  // Comment this
  void InsertSubject(int CourseId, int SubjectId, string SubjectName){
    // Comment this
    Course* SubjectCourse = Head;
    // Comment this
    while(SubjectCourse != NULL){
      // Comment this
      if(SubjectCourse->GetCourseID() == CourseId){
        // Comment this
        SubjectCourse->GetSubjects().NewSubject(SubjectId, SubjectName);
      }
      SubjectCourse = SubjectCourse->Next;
    }
  }

  // Comment this
  void CourseAvailable(){
    Course* CurrentCourse = Head;
    // Comment this
    if(CurrentCourse == NULL){
      std::cout<<"No course is available at the moment\n";
    }
    // Comment this
    while(CurrentCourse != NULL){
      std::cout<<"#========================#\n";
      std::cout<<"Course List: \n";
      std::cout<<CurrentCourse->GetCourseName()<<"\n";
      std::cout<<"Subjects to take: \n";
      CurrentCourse->GetSubjects().ShowSubjectList();
      std::cout<<"#========================#\n";
      CurrentCourse = CurrentCourse->Next;
    }
  }

};
