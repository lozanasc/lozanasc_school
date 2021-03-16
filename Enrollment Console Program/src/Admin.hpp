/*
  Made by: Sean Christian Lozana
*/

// Dependency Imports
#include <iostream>
#include "Registrar.hpp"
#include "Enrollment.hpp"

/*
  Admin class is responsible for storing Admin information in a LinkedList data structure
  Admins can do the ff:
  * Login
  * Register
  * Add Course in the Course List
  * Delete Course in the Course List
  * Review and Accept Enrollment Status
  * View entire Enrollee list
*/
class Admin {
public:
  class User {
    string Name, Password;
  public:
    User* Next;
    /*
      User constructor that will initialize Admin user basic information like:
      Username and Password
    */
    User(string Name, string Password){
      this->Name = Name;
      this->Password = Password;
      Next = NULL;
    }
    /*
      These getter functions will be useful for Authentication purposes
      however please do note that security is not taken into account.
    */
    // Getter function for grabbing Username in a string format
    string GetName(){
      return this->Name;
    }
    // Getter function for grabbing Password in a string format
    string GetPassword(){
      return this->Password;
    }
  };

  /*
    This is where the magic begins....
    (and by Magic smelly code and idk what style of code this is)
  */
  /*
    Nesting Linked Lists in Admin for Registrar and Enrollment accessbility
    If you'll ask me why, I don't know this seems like a good idea to me
    Don't know how this will scale with bigger inputs, space-complexity wise
    This is very inefficient I reckon...
  */
  Registrar CourseList;
  Enrollment Enroll;

  /*
    Initializes the Head node pointing to NULL as its initial state which tells you
    that the initial state of the List is empty...
  */
  User* Head = NULL;

  /*
    This function is responsible for inserting new nodes into the List
    @params {string} Username for Admin identification
    @params {string} Password for Admin authentication
  */
  void CreateAccount(string Username, string Password){
    // Comment this
    User* NewAccount = new User(Username, Password);
    // Comment this
    Head == NULL ? Head = NewAccount : NewAccount->Next = Head; Head = NewAccount;
  }
  /*
    This function is responsible for searching Admin account in the list
    @params {string} Username used as key for the search
    @returns {bool} IsFound true if a Name of a Node is equal to the argument passed
  */
  bool AccountCheck(string Username){
    // Initial state of the search
    bool IsFound = false;
    // Referrencing the Head node for the Temp node CurrentAccount
    User* CurrentAccount = Head;
    /*
      Traverses the entire list if the condition that the pointer
      CurrentAccount is pointing at something not NULL will continue
      to traverse the entire list
    */
    while(CurrentAccount != NULL){
      /*
        Condition that will re-assign the IsFound boolean variable to true if and only if
        the Current's node Name is the same with the parameter Username.
      */
      if(CurrentAccount->GetName() == Username){
        IsFound = true;
      }
      // CurrentAccount pointer will point to the memory address of the next node until it reaches NULL
      CurrentAccount = CurrentAccount->Next;
    }
    //
    return IsFound;
  }
  /*
    This function is responsible Authentication and possibly crimes against humanity...
    @params {string} Username used Identification and authentication
    @params {string} Password used for authentication
  */
  void Login(string Username, string Password){
    // Referrencing temp pointer with the Head node
    User* AccountToVerify = Head;
    // If the temp points at null the list is possibly empty
    if(AccountToVerify == NULL)
      std::cout<<"Such account doesn't exist in the database\n";
    // If the temp points at an address and not null will proceed to traverse the entire list
    while(AccountToVerify != NULL){
      // The authentication logic that checks if the current node's name and password checks out with the arguments passed
      if(AccountToVerify->GetName() == Username && AccountToVerify->GetPassword() == Password){
        clear();
        // If the condition is met a sub-loop is executed
        // boolean variable that controls the loop
        bool Session = true;
        // The sub-loop responsible for logon/dashboard session
        while(Session){
        int Choice;
        std::cout<<"#=======================================#\n";
        std::cout<<"#  █▀▄ ▄▀▄ ▄▀▀ █▄█ ██▄ ▄▀▄ ▄▀▄ █▀▄ █▀▄  #\n";
        std::cout<<"#  █▄▀ █▀█ ▄██ █ █ █▄█ ▀▄▀ █▀█ █▀▄ █▄▀  #\n";
        std::cout<<"#=======================================#\n";
        std::cout<<"[User in Session: ] "<<AccountToVerify->GetName()<<"\n";
        std::cout<<"#=======================================#\n";
        std::cout<<"[1] Course Options\n";
        std::cout<<"[2] Show Enrollee List\n";
        std::cout<<"[3] Change of Enrollment Status\n";
        std::cout<<"[4] End Session\n";
        std::cout<<"[CHOICE:] ";std::cin>>Choice;
        switch(Choice){
          /*
            This case is responsible for housing the options that admin can do with anything related to Courses
            Which includes the ff:
            * Create and add new Course to the Course List
            * Output all the Courses in the List
            * Delete Course
            * Exit that breaks from the course session loop and goes back to the login session loop
          */
          case 1: {
            clear();
            // boolean variable that controls the loop
            bool CourseSession = true;
            // The sub-loop for the Login session loop that is responsible for Course options session
            while(CourseSession){
              int Choice;
              std::cout<<"#================================================================#\n";
              std::cout<<"#                        Course Options                          #\n";
              std::cout<<"#================================================================#\n";
              std::cout<<"#        [1] Add new Course                                      #\n";
              std::cout<<"#        [2] Show all Courses                                    #\n";
              std::cout<<"#        [3] Remove Course                                       #\n";
              std::cout<<"#        [4] Exit                                                #\n";
              std::cout<<"#================================================================#\n";
              std::cout<<"[CHOICE: ] ";std::cin>>Choice;
              switch (Choice) {
                /*
                  This case is responsible for adding new courses to the course list
                */
                case 1:{
                  clear();
                  int CourseId;
                  string CourseName;
                  std::cout<<"#================================================================#\n";
                  std::cout<<"#                        Adding of Course                        #\n";
                  std::cout<<"#================================================================#\n";
                  std::cout<<"[Enter Course Id: ] ";std::cin>>CourseId;
                  std::cout<<"[Enter Course Name: ] ";std::cin>>CourseName;
                  CourseList.CreateCourse(CourseId, CourseName);
                  break;
                }
                // This case is responsible for outputting all existing courses in the course list
                case 2:{
                  clear();
                  CourseList.GetCourseList();
                  break;
                }
                // This case is responsible for deleting a course granted that the said course exists in the list
                case 3: {
                  int CourseToDelete;
                  int PositionById;
                  std::cout<<"[Course Available: ]\n";
                  CourseList.GetCourseList();
                  std::cout<<"[Enter Course Id ] ";std::cin>>CourseToDelete;
                  PositionById = CourseList.SearchByPosition(CourseToDelete);
                  // Outputs the position in the list that is 0-based indexing
                  std::cout<<"Course Position is at Index:  "<<PositionById<<"\n";
                  /*
                    Deletes a Course by Course Id
                    This is actually pretty inefficient since I still have to call SearchByPosition function
                    that will return the index based on the Course Id.

                    The SearchByPosition function will have to traverse the entire list to search for the index
                    then the DeleteCourse will do the same thing, will traverse the entire list to search for the node by
                    the index returned by the SearchByPosition function.
                  */
                  CourseList.DeleteCourse(PositionById);
                  break;
                }
                // Breaks out from the CourseSession loop and goes back to the Login Sesssion loop
                case 4: {
                  CourseSession = false;
                  break;
                }
                // If input is invalid proceeds to break out from the CourseSession loop and goes back to the Login Sesssion loop
                default:
                  CourseSession = false;
                  break;
              }
            }
            break;
          }
          /*
            This case is responsible for outputting all the enrollee's in the enrollment list
          */
          case 2: {
            clear();
            Enroll.GetEnrolleeList();
            break;
          }
          /*
            This case is responsible for approving or disapproving a enrollee acceptance status
          */
          case 3: {
            clear();
            Enroll.GetEnrolleeList();
            bool ApprovalStatus;
            string Username;
            std::cout<<"#================================================================#\n";
            std::cout<<"#                 Review and Approval of Student                 #\n";
            std::cout<<"#================================================================#\n";
            std::cout<<"[ Search Student Enrollee by Username: ] ";std::cin>>Username;
            std::cout<<"[ Type (1) to Approve and (0) to Deny: ] ";std::cin>>ApprovalStatus;
            Enroll.ChangeEnrollmentStatus(Username, ApprovalStatus);
            break;
          }
          // Case responsible for breaking from the Login session loop
          case 4: {
            Session = false;
            break;
          }
          // If input is invalid the case will just break and go back to the start of the loop
          default:
            std::cout<<"Wrong input \n";
            break;
        }
        }
      }
      // If the authentication failed will output error message
      else
        std::cout<<"Wrong username or password\n";
      // Traverses the entire list looking for the right Name and Password that is equal to the parameters passed
      AccountToVerify = AccountToVerify->Next;
      }
    }

  /*
    Function that wraps the CheckCourseAvailability inside the CourseList class so that it will available to Admin class
    @returns {bool} true if the Course searched by name exists in the CourseList otherwise false
  */
  bool CheckCourseAvailability(string CourseName){
      return CourseList.CheckCourseAvailability(CourseName);
    }
  /*
    Function that wraps the GetCourseList inside the CourseList class so that it will available to Admin class
    Outputs the all the Courses available in the CourseList
  */
  void ShowCourseList(){
      CourseList.GetCourseList();
    }

  /*
    Function that wraps the EnrollNewStudent function to be made available to the class Admin
    Responsible for adding new enrollee's to the enrollment list however has a condition that checks the Course availability
  */
  void EnrollmentForm(int Id, string Fname, string Lname, string Username, string Password, string Course){
      if(CheckCourseAvailability(Course))
        Enroll.EnrollNewStudent(Id, Fname, Lname, Username, Password, Course);
      else
        std::cout<<"Sorry course not yet available :C \n";
    }
    /*
      Function that wraps the Login for Enrollee's to be made available to the class Admin
    */
  void EnrolleeLogin(string Username, string Password){
      Enroll.Login(Username, Password);
    }
};
