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

// TODO:
// Create a Menu Interface
void Start(){
  int choice;
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
  cout << "#         [2] Sign in                                                                                         # \n";
  cout << "#                                                                                                             # \n";
  cout << "#=============================================================================================================# \n";
  cout << "[CHOICE] => ";cin >> choice;
  switch(choice){
    case 1: {
      cout << "Hitting create account! \n";
      break;
    }
    case 2: {
      cout << "Hitting sign on account! \n";
      break;
    }
    default:
      clear();
      cout << "Wrong input! \n";
      cin.get();
      break;
  }
}

// Main driver function
int main(){
  Start();
  return 0;
}
