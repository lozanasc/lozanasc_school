/*
  Made by: Sean Christian Lozana
*/
// Dependency Imports
#include <iostream>

#include "Admin.hpp" // Manages basically everything at this point...
#include "TerminalClear.hpp"

using std::cout;
using std::cin;

/*
  Global Variables
  Do note that they're bad practice in general
  Read here why:
  https://www.tutorialspoint.com/why-are-global-variables-bad-in-c-cplusplus
*/
Admin Faculty;

// Comment this
void Start(){
  bool Session = true;
  while(Session){
    clear();
    int Choice;
    cout<<"#================================================================#\n";
    cout<<"#        Negros Oriental State University Enrollment System      #\n";
    cout<<"#================================================================#\n";
    cout<<"#        [1] Enroll                                              #\n";
    cout<<"#        [2] Admin Options                                       #\n";
    cout<<"#        [3] Check Enrollment Status                             #\n";
    cout<<"#        [4] Exit                                                #\n";
    cout<<"#================================================================#\n";
    cout<<"[CHOICE: ] ";cin>>Choice;
    switch (Choice) {
      // Comment this
      case 1: {
        clear();
        int Id;
        string Fname, Lname, Username, Password, Course;
        cout<<"#================================================================#\n";
        cout<<"#                        Enrollment Form                         #\n";
        cout<<"#================================================================#\n";
        cout<<"[Enter First name: ] ";cin>>Fname;
        cout<<"[Enter Last name: ] ";cin>>Lname;
        cout<<"[Enter User name: ] ";cin>>Username;
        cout<<"[Enter Password: ] ";cin>>Password;
        clear();
        Faculty.ShowCourseList();
        cout<<"[Enter Course: ] ";cin>>Course;
        Faculty.EnrollmentForm(Id, Fname, Lname, Username, Password, Course);
        break;
      }
      // Comment this
      case 2:{
        bool AdminSession = true;
        while(AdminSession){
          clear();
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
              string Username, Password;
              cout<<"#================================================================#\n";
              cout<<"#                       Admin Registration                       #\n";
              cout<<"#================================================================#\n";
              cout<<"[Enter username: ] ";cin>>Username;
              cout<<"[Enter password: ] ";cin>>Password;
              Faculty.CreateAccount(Username, Password);
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
        break;
      }
      case 3: {
        clear();
        string Username, Password;
        cout<<"#================================================================#\n";
        cout<<"#                       Enrollee Login                           #\n";
        cout<<"#================================================================#\n";
        cout<<"[Enter username: ] ";cin>>Username;
        cout<<"[Enter password: ] ";cin>>Password;
        Faculty.EnrolleeLogin(Username, Password);
        break;
      }
      // Comment this
      case 4:{
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
