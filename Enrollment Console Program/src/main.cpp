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
    int Choice;
    cout<<"#================================================================#\n";
    cout<<"#        Negros Oriental State University Enrollment System      #\n";
    cout<<"#        [1] Enroll                                              #\n";
    cout<<"#        [2] Admin Login                                         #\n";
    cout<<"#        [3] Exit                                                #\n";
    cout<<"#================================================================#\n";
    cout<<"[CHOICE:]";cin>>Choice;
    switch (Choice) {
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
        Student.EnrollNewStudent(Id, Fname, Lname);
        break;
      }
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
          case 1: {
            cout<<"#================================================================#\n";
            cout<<"#                         Admin Sign-on                          #\n";
            cout<<"#================================================================#\n";
            string Username, Password;
            cout<<"Username: ";cin>>Username;
            cout<<"Password: ";cin>>Password;
            clear();
            Faculty.Login(Username, Password);
            break;
          }
          case 2: {
            cout<<"#================================================================#\n";
            cout<<"#                         Registration                           #\n";
            cout<<"#================================================================#\n";
            string Username, Password;
            cout<<"Username: ";cin>>Username;
            cout<<"Password: ";cin>>Password;
            Faculty.CreateAccount(Username, Password);
            break;
          }
          case 3: {
            break;
          }
          default:
            break;
        }
        break;
      }
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
  Start(Student, Faculty);
  return 0;
}
