/*
  Made by: Sean Christian Lozana
  Linked List that will create, store, retrieve Courses and related Subjects
*/
// Read more about this feature -> https://en.wikipedia.org/wiki/Pragma_once
#pragma once

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
    // Comment this
    SubjectLookup Subjects;
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

    // Comment this
    SubjectLookup GetSubjects(){
      return this->Subjects;
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

  void InsertSubject(int CourseId, int SubjectId, string SubjectName){
    Course* SubjectCourse = Head;
    if(SubjectCourse == NULL)
      std::cout<<"No course available\n";
    while(SubjectCourse != NULL){
      if(SubjectCourse->GetCourseID() == CourseId){
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
      return;
    }
    // Comment this
    while(CurrentCourse != NULL){
      std::cout<<"#========================#\n";
      std::cout<<"Course List: \n";
      std::cout<<CurrentCourse->GetCourseName()<<"\n";
      std::cout<<"Subjects to take: \n";
      CurrentCourse->GetSubjects().ShowSubjectList();
      std::cout<<"#========================#\n";
    }
  }

};
