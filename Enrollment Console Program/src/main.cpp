/*
  Made by: Sean Christian Lozana
*/
// Dependency Imports
#include <iostream>
#include "Enrollment.hpp" // Creates, Retrieve and Store Student Information
#include "Admin.hpp" // Manages the Courses and Subjects per each Course
#include "Registrar.hpp"

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

// Comment this
void Start(Enrollment Student, Admin Faculty, Registrar Norsu){
  bool Session = true;
  while(Session){
    int Choice;
    cout<<"#================================================================#\n";
    cout<<"#        Negros Oriental State University Enrollment System      #\n";
    cout<<"#        [1] Enroll                                              #\n";
    cout<<"#        [2] Admin Options                                       #\n";
    cout<<"#        [3] Exit                                                #\n";
    cout<<"#================================================================#\n";
    cout<<"[CHOICE:]";cin>>Choice;
    switch (Choice) {
      // Comment this
      case 1: {
        clear();
        int Id;
        string Fname, Lname;
        cout<<"#================================================================#\n";
        cout<<"#                      Enrollment Form                           #\n";
        cout<<"#================================================================#\n";
        cout<<"Enter Enrollment Id: ";cin>>Id;
        cout<<"Enter First name: ";cin>>Fname;
        cout<<"Enter Last name: ";cin>>Lname;
        // Comment this
        Student.EnrollNewStudent(Id, Fname, Lname);
        break;
      }
      // Comment this
      case 2:{
        clear();
        int Choice;
        cout<<"#================================================================#\n";
        cout<<"#        Negros Oriental State University Enrollment System      #\n";
        cout<<"#        [1] Admin Login                                         #\n";
        cout<<"#        [2] Admin Registration                                  #\n";
        cout<<"#        [3] Exit                                                #\n";
        cout<<"#================================================================#\n";
        cout<<"[CHOICE:]";cin>>Choice;
        switch(Choice){
          // Comment this
          case 1: {
            cout<<"#================================================================#\n";
            cout<<"#                         Admin Sign-on                          #\n";
            cout<<"#================================================================#\n";
            string Username, Password;
            cout<<"Username: ";cin>>Username;
            cout<<"Password: ";cin>>Password;
            clear();
            // Comment this
            Faculty.Login(Username, Password);
            break;
          }
          // Comment this
          case 2: {
            cout<<"#================================================================#\n";
            cout<<"#                         Registration                           #\n";
            cout<<"#================================================================#\n";
            string Username, Password;
            cout<<"Username: ";cin>>Username;
            // Comment this
            if(Faculty.AccountCheck(Username)){
              cout<<"Password: ";cin>>Password;
              // Comment this
              Faculty.CreateAccount(Username, Password, Norsu);
            }
            else
              cout<<"Sorry conflicting username in the database please choose a new one.\n";
            break;
          }
          // Comment this
          case 3: {
            break;
          }
          default:
            break;
        }
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
  Enrollment Student;
  Admin Faculty;
  Registrar Norsu;
  Start(Student, Faculty, Norsu);
  return 0;
}
