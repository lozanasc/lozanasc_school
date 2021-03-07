/*
  Made by: Sean Christian Lozana
  A program made in the 1st semester of AY 2018-2019 BS Computer Science
*/
// Dependency Imports
#include <iostream>
#include "Machine.hpp"

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

using std::cout;
using std::cin;
using std::string;

/*
  The Start function contains the main interface of the Program
  @params {class} ATM will be the List for storing and creating Accounts
*/
void Start(Machine ATM){
  bool UseSession = true;
  // Persists the Use session
  while(UseSession){
    int Choice;
    cout << "#=============================================================================================================# \n";
    cout << "#                                                                                                             # \n";
    cout << "#                                                                                                             # \n";
    cout << "#        █████╗ ████████╗███╗   ███╗    ████████╗███████╗██████╗ ███╗   ███╗██╗███╗   ██╗ █████╗ ██╗          # \n";
    cout << "#       ██╔══██╗╚══██╔══╝████╗ ████║    ╚══██╔══╝██╔════╝██╔══██╗████╗ ████║██║████╗  ██║██╔══██╗██║          # \n";
    cout << "#       ███████║   ██║   ██╔████╔██║       ██║   █████╗  ██████╔╝██╔████╔██║██║██╔██╗ ██║███████║██║          # \n";
    cout << "#       ██╔══██║   ██║   ██║╚██╔╝██║       ██║   ██╔══╝  ██╔══██╗██║╚██╔╝██║██║██║╚██╗██║██╔══██║██║          # \n";
    cout << "#       ██║  ██║   ██║   ██║ ╚═╝ ██║       ██║   ███████╗██║  ██║██║ ╚═╝ ██║██║██║ ╚████║██║  ██║███████╗     # \n";
    cout << "#       ╚═╝  ╚═╝   ╚═╝   ╚═╝     ╚═╝       ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝     # \n";
    cout << "#                                                                                                             # \n";
    cout << "#                                                                                                             # \n";
    cout << "#         Made by: Sean Christian Lozana                                                                      # \n";
    cout << "#         [1] Create Account                                                                                  # \n";
    cout << "#         [2] Log-in                                                                                           # \n";
    cout << "#         [3] Exit                                                                                            # \n";
    cout << "#                                                                                                             # \n";
    cout << "#=============================================================================================================# \n";
    cout << "[CHOICE] => ";cin >> Choice;
    switch(Choice){
      case 1: {
        clear();
        int Pin;
        string Name;
        double Balance;
        cout << "#=============================================================================================================# \n";
        cout << "# Account Registration Form:                                                                                  # \n";
        cout << "#=============================================================================================================# \n";
        cout<<"  [Enter PIN:] ";cin>>Pin;cout<<"\n";
        if(ATM.AccountCheck(Pin)){
          cout<<"  [Enter Name:] ";cin>>Name;cout<<"\n";
          cout<<"  [Enter Initial Deposit:] ";cin>>Balance;cout<<"\n";
          ATM.CreateAccount(Name, Pin, Balance);
          clear();
        }
        else {
          cout<<"Sorry a user has already associated this PIN \n";
        }
        break;
      }
      case 2: {
        int Pin;
        char Choice;
        cout<<"Enter PIN to Login: ";cin>>Pin;
        clear();
        ATM.Login(Pin);
        cout<<"Would you like to go back to the Menu? Y/N \n CHOICE: ";cin>>Choice;
        switch(Choice){
          case 'Y': {
            clear();
            break;
          }
          case 'N': {
            clear();
            cout<<"Bye!";
            UseSession = false;
            break;
          }
          default:
          return;
        }
        break;
      }
      case 3: {
        UseSession = false;
        break;
      }
      default:
      clear();
      cout << "Wrong input! \n";
      break;
    }
  }
}

// Main driver function
int main(){
  Machine ATM;
  Start(ATM);
  return 0;
}
