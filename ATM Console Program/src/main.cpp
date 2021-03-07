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


// TODO:
// Create a Menu Interface
void Start(Machine ATM){
  bool InUse = true;
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
  cout << "#         [2] Login                                                                                           # \n";
  cout << "#         [3] Exit                                                                                            # \n";
  cout << "#                                                                                                             # \n";
  cout << "#=============================================================================================================# \n";
  cout << "[CHOICE] => ";cin >> Choice;
  switch(Choice){
    case 1: {
      int Pin;
      string Name;
      double Balance;
      cout<<"Enter PIN: ";cin>>Pin;cout<<"\n";
      cout<<"Enter Name: ";cin>>Name;cout<<"\n";
      cout<<"Enter Initial Deposit: ";cin>>Balance;cout<<"\n";
      ATM.CreateAccount(Name, Pin, Balance);
      Start(ATM); //Recurses back to the Menu
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
          Start(ATM);
        }
        case 'N': {
          clear();
          cout<<"Bye!";
          return;
        }
        default:
          cout<<"Wrong house fool!";
      }
      break;
    }
    case 3: {
      return;
    }
    default:
      clear();
      cout << "Wrong input! \n";
      return;
  }
}

// Main driver function
int main(){
  Machine ATM;
  Start(ATM);
  return 0;
}
