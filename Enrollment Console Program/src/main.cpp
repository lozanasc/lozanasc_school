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

// Start function that is responsible for housing the entire menu interface program
void Start(){
  /* Session condition that will control the main flow of the program
     true -> Program will continue
     false -> Program will terminate
  */
  bool Session = true;
  // Main loop of the Program
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
      /*
        This case contains the Enrollment process which is the main purpose of the program,
        there is a condition however for a successful enrollment process, the admin should
        populate the course list inorder for students to be able to enroll.
      */
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
        // Shows a list courses available to enroll in
        Faculty.ShowCourseList();
        cout<<"[Enter Course: ] ";cin>>Course;
        // Adds a new enrollee to the Enrollment list
        Faculty.EnrollmentForm(Id, Fname, Lname, Username, Password, Course);
        break;
      }
      /*
        This case contains options available for the Admin component which are:
        * Logging in
        * Registration
        * Exit or break out from the sub-loop
      */
      case 2:{
        /* Sub-loop that is responsible for the Admin session
          true -> Admin session loop will continue
          false -> Admin session breaks out and goes back to the main loop
        */
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
            /*
              This case is responsible for the Admin Login form
            */
            case 1: {
              clear();
              string Username, Password;
              cout<<"#================================================================#\n";
              cout<<"#                         Admin Sign-on                          #\n";
              cout<<"#================================================================#\n";
              cout<<"[Enter username: ] ";cin>>Username;
              cout<<"[Enter password: ] ";cin>>Password;
              /*
                If Login is successful, proceed to Dashboard inside the Login function
                Else will go back to the admin session loop since Login function will terminate
              */
              Faculty.Login(Username, Password);
              break;
            }
            /*
              This case is responsible for the Registration of Admin user agents
            */
            case 2:{
              clear();
              string Username, Password;
              cout<<"#================================================================#\n";
              cout<<"#                       Admin Registration                       #\n";
              cout<<"#================================================================#\n";
              cout<<"[Enter username: ] ";cin>>Username;
              cout<<"[Enter password: ] ";cin>>Password;
              // Adds a new account to the Admin List
              Faculty.CreateAccount(Username, Password);
              break;
            }
            // Breaks the admin session loop out and goes back to the main session loop
            case 3:{
              AdminSession = false;
              break;
            }
            // In cases where input is invalid the admin session loop will automatically break
            default:
            AdminSession = false;
            break;
          }
        }
        break;
      }
      /*
        This case contains the Login for Enrollee for authentication
      */
      case 3: {
        clear();
        string Username, Password;
        cout<<"#================================================================#\n";
        cout<<"#                       Enrollee Login                           #\n";
        cout<<"#================================================================#\n";
        cout<<"[Enter username: ] ";cin>>Username;
        cout<<"[Enter password: ] ";cin>>Password;
        /*
          If Login is successful, proceed to Dashboard inside the Login function
          Else will go back to the session loop since Login function will terminate
        */
        Faculty.EnrolleeLogin(Username, Password);
        break;
      }
      // Breaks the Main session loop and terminates the entire program
      case 4:{
        Session = false;
        break;
      }
      // In cases where input is invalid main session loop will automatically break out of the loop and terminates program
      default:
        Session = false;
        break;
    }
  }
}


// Main driver function
int main(){
  // Start functional invokation at main function
  Start();
  // Program termination
  return 0;
}
