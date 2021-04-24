/*
  Made by: Sean Christian Lozana
*/
#include <iostream>
#include "Clear.hpp"
#include "Shop.hpp"

/*
  Global Variables
  Do note that they're bad practice in general
  Read here why:
  https://www.tutorialspoint.com/why-are-global-variables-bad-in-c-cplusplus
*/
Shop Cafe;

void Start(){
  clear();
  // Main program session
  bool ProgramSession = true;
  while(ProgramSession){
    int Choice;
    std::cout<<"[===================================]\n";
    std::cout<<"[ [1] Login                         ]\n";
    std::cout<<"[ [2] Register                      ]\n";
    std::cout<<"[ [3] Exit                          ]\n";
    std::cout<<"[===================================]\n";
    std::cout<<"[ Choice ] : ";std::cin>>Choice;
    switch (Choice) {
      // This case is responsible for signing in Salesperson
      case 1: {
        clear();
        string Name, Pass;
        std::cout<<"[===================================]\n";
        std::cout<<"[              Sign-in              ]\n";
        std::cout<<"[===================================]\n";
        std::cout<<"[ Enter username ] : ";std::cin>>Name;
        std::cout<<"[ Enter password ] : ";std::cin>>Pass;
        Cafe.Login(Name, Pass);
        break;
      }
      // This case is responsible for signing up Salesperson
      case 2: {
        clear();
        int Id;
        string CompleteName, Name, Pass;
        std::cout<<"[===================================]\n";
        std::cout<<"[              Sign-up              ]\n";
        std::cout<<"[===================================]\n";
        std::cout<<"[ Enter Id ] : ";std::cin>>Id;
        std::cout<<"[ Enter fullname ] : ";std::cin>>CompleteName;
        std::cout<<"[ Enter username ] : ";std::cin>>Name;
        std::cout<<"[ Enter password ] : ";std::cin>>Pass;
        Cafe.CreateAccount(Id, CompleteName, Name, Pass);
        break;
      }
      // This case is responsible for terminating the main program loop thus ending the program
      case 3: {
        ProgramSession = false;
        break;
      }
      default:
        break;
    }
  }
}

int main(){
  Start();
  return 0;
}
