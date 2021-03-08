/*
  Made by: Sean Christian Lozana
*/
// Dependency Imports
#include <iostream>
#include "Enrollment.hpp" // Creates, Retrieve and Store Student Information
#include "Admin.hpp" // Manages the Courses and Subjects per each Course


using std::cout;
using std::cin;
using std::string;

/*
  Makes sure clearing the terminal on both Linux and Windows works
  However please do note that the use of system function calls is not recommended
  Read here:
  http://www.cplusplus.com/articles/j3wTURfi/
*/
#ifdef __linux__
  void clear(){
    system("clear");
  }
#elif _WIN32
  void clear(){
    system("cls");
  }
#endif

void Start(Enrollment Student, Admin Faculty){
  bool Session = true;
  while(Session){

  }
}

// Main driver function
int main(){
  Enrollment Student;
  Admin Faculty;
  Start(Student, Faculty);
  return 0;
}
