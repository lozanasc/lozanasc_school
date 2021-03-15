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
    string SubjectName, Course;
  public:
    StudentSubject* Next;
    // Comment this
    StudentSubject(int Id, string Name, string Course){
      this->SubjectId = Id;
      this->SubjectName = Name;
      this->Course = Course;
    }
    // Comment this
    int GetStudentId(){
      return this->SubjectId;
    }
    // Comment this
    string GetSubjectName(){
      return this->SubjectName;
    }
    string GetSubjectCourse(){
      return this->Course;
    }
  };
  // Comment this
  StudentSubject* Head = NULL;

  // Comment this
  void NewSubject(int Id, string Name, string Course){
    // Comment this
    StudentSubject* NewSubject = new StudentSubject(Id, Name, Course);
    // Comment this
    Head == NULL ? Head = NewSubject : NewSubject->Next = Head; Head = NewSubject;
  }

  void ShowAllSubject(){
    StudentSubject* CurrentSubject = Head;

    if(CurrentSubject == NULL)
      std::cout<<"There's no subject in the list \n";

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

};
