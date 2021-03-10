/*
  Made by: Sean Christian Lozana
*/
// Dependency Imports
#include <iostream>
#include "Enrollment.hpp" // Creates, Retrieve and Store Student Information
#include "Admin.hpp" // Manages the Courses and Subjects per each Course


using std::cout;
using std::cin;

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

/*
  Global Variables
  However please take note that they're bad practice in general
  Read here:
  https://dev.to/mervinsv/why-global-variables-are-bad-4pj
*/
Enrollment Student;
Admin Faculty;
Registrar Norsu;

void AdminInterface(Admin Faculty);

// Comment this
void Start(){
  bool Session = true;
  while(Session){
    int Choice;
    cout<<"#================================================================#\n";
    cout<<"#        Negros Oriental State University Enrollment System      #\n";
    cout<<"#================================================================#\n";
    cout<<"#        [1] Enroll                                              #\n";
    cout<<"#        [2] Admin Options                                       #\n";
    cout<<"#        [3] Exit                                                #\n";
    cout<<"#================================================================#\n";
    cout<<"[CHOICE:]";cin>>Choice;
    switch (Choice) {
      // Comment this
      case 1: {
        clear();
        // Todo here
        break;
      }
      // Comment this
      case 2:{
        AdminInterface(Faculty);
        break;
      }
      // Comment this
      case 3:{
        Session = false;
        break;
      }
      default:
        Session = false;
        break;
    }
  }
}


// Main driver function
int main(){
  Start();
  return 0;
}

void AdminInterface(Admin Faculty){
  bool AdminSession = true;
  while(AdminSession){
    int Choice;
    cout<<"#================================================================#\n";
    cout<<"#                         Admin Options                          #\n";
    cout<<"#================================================================#\n";
    cout<<"#        [1] Login                                               #\n";
    cout<<"#        [2] Register                                            #\n";
    cout<<"#        [3] Exit                                                #\n";
    cout<<"#================================================================#\n";
    cout<<"[CHOICE: ] ";cin>>Choice;
    switch (Choice) {
      case 1: {
        clear();
        string Username, Password;
        cout<<"#================================================================#\n";
        cout<<"#                         Admin Sign-on                          #\n";
        cout<<"#================================================================#\n";
        cout<<"[Enter username: ] ";cin>>Username;
        cout<<"[Enter password: ] ";cin>>Password;
        Faculty.Login(Username, Password);
        break;
      }
      // Comment this
      case 2:{
        clear();
        break;
      }
      // Comment this
      case 3:{
        AdminSession = false;
        break;
      }
      default:
      AdminSession = false;
      break;
    }
  }
}
