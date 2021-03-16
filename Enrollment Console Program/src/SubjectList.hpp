/*
  Made by: Sean Christian Lozana
*/
#include <iostream>

// This class is responsible for storing Subjects for each Enrollee's
class SubjectList {
public:
  class StudentSubject{
    int SubjectId;
    string SubjectName, Course;
  public:
    StudentSubject* Next;
    /*
      Constructor that initializes Subject's Id, Name and Course
      @params {integer} Id for Identification
      @params {string} Name for Identification
      @params {string} Course for Subject's Program
    */
    StudentSubject(int Id, string Name, string Course){
      this->SubjectId = Id;
      this->SubjectName = Name;
      this->Course = Course;
    }
    // Returns Subject's Subject Id
    int GetStudentId(){
      return this->SubjectId;
    }
    // Returns Subject's Subject Name
    string GetSubjectName(){
      return this->SubjectName;
    }
    // Returns Subject's Course
    string GetSubjectCourse(){
      return this->Course;
    }
  };
  // Initializes the Head node pointer to NULL as its initial state
  StudentSubject* Head = NULL;

  /*
    This function is responsible for Creating and Inserting a new Subject
    In the SubjectList
    @params {integer} Id for Identification
    @params {string} Name for Identification
    @params {string} Course for Subject's Program
  */
  void NewSubject(int Id, string Name, string Course){
    StudentSubject* NewSubject = new StudentSubject(Id, Name, Course);
    Head == NULL ? Head = NewSubject : NewSubject->Next = Head; Head = NewSubject;
  }

  // This function outputs the entire Subject List
  void ShowAllSubject(){
    StudentSubject* CurrentSubject = Head;

    if(CurrentSubject == NULL)
      std::cout<<"There's no subject in the list \n";
    else {
      std::cout<<"#================================================================#\n";
      std::cout<<"#                        Subject List                            #\n";
      std::cout<<"#================================================================#\n";
      while (CurrentSubject != NULL) {
        std::cout<<"  "<<CurrentSubject->GetSubjectName()<<"\n";
        std::cout<<"  "<<CurrentSubject->GetSubjectCourse()<<"\n";
        CurrentSubject = CurrentSubject->Next;
      }
      std::cout<<"#================================================================#\n";
    }
  }

};
