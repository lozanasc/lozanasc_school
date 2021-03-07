/*
  Made by: Sean Christian  Lozana
  A Linked List that will act as the Automated Teller Machine that will store, add, delete Account Information
*/

// Dependency Imports
#include <iostream>

using std::string;

class Machine {
  public:
  class Account {
      // Name of the User
      string Name;
      // Pin for Identification and Authorization
      int Pin;
      // The amount of money existing in the Banke
      double Balance;
      public:
        Account* Next;
        /*
          Constructor that initializes a new object with paramters:
          @params {String} Name -> Name of the Customer
          @params {Integer} Pin -> Identification PIN for Authorization
          @param {Double} Balance -> To set initial balance of the Account
        */
        Account(string Name, int Pin, double Balance){
          this->Name = Name;
          this->Pin = Pin;
          this->Balance = Balance;
          Next = NULL;
        }
        // Grabs the instance var Pin
        int GetPin(){
          return this->Pin;
        }
        // Grabs the instance var Name
        string GetName(){
          return this->Name;
        }
        // Grabs the instance var Balance
        double GetBalance(){
          return this->Balance;
        }
        // ! Subject for testing
        double UpdateBalance(double Amount, char Operator){
          switch (Operator) {
            case '+': {
              return this->Balance += Amount;
            }
            case '-': {
              return this->Balance -= Amount;
            }
            default:
              return this->Balance;
          }
        }
    };

    // Allocates the headptr and points it to null as its initial state
    class Account* Head = NULL;
    // Allocates the Lastptr and points it to null as its initial state
    class Account* Last = NULL;
    /*
      Creates a new node containing new Account Information
      @params {String} SetName -> Set's account user Name
      @param {Integer} SetPin -> Set's account Pin number
      @param {Double} InitialDeposit -> All account must have contain a balance
    */
    void CreateAccount(string SetName, int SetPin, double InitialDeposit){
      Account* NewAccount = new Account(SetName, SetPin, InitialDeposit);
      Head == NULL ? Head = Last = NewAccount : NewAccount->Next = Head; Head = NewAccount;
    }
    
    void Login(int VerifyPin){
      Account* CurrentAccount = Head;
      if(CurrentAccount == NULL){
        std::cout<<"No account is registered \n";
        return;
      }
      while(CurrentAccount != NULL) {
        if(VerifyPin==CurrentAccount->GetPin()){
          int Choice;
          bool LoggedIn = true;
          std::cout<<"#=====================================#\n";
          std::cout<<"# █   █ ██▀ █   ▄▀▀ ▄▀▄ █▄ ▄█ ██▀     #\n";
          std::cout<<"# ▀▄▀▄▀ █▄▄ █▄▄ ▀▄▄ ▀▄▀ █ ▀ █ █▄▄     #\n";
          std::cout<<"#=====================================#\n";
          std::cout<<"# User Information:                   #\n";
          std::cout<<"#=====================================#\n";
          std::cout<<"Pin: "<<CurrentAccount->GetPin()<<"    \n";
          std::cout<<"Name: "<<CurrentAccount->GetName()<<"  \n";
          std::cout<<"Balance: "<<CurrentAccount->GetBalance()<<"\n";
          while(LoggedIn){
            std::cout<<"[USER OPTIONS] \n [1][Deposit] \n [2][Withdraw] \n [3][View Balance] \n [4][Exit] \n CHOICE: ";
            std::cin>>Choice;
            switch(Choice){
              case 1: {
                double Amount;
                std::cout<<"Enter amount: ";std::cin>>Amount;
                CurrentAccount->UpdateBalance(Amount, '+');
                break;
              }
              case 2: {
                double Amount;
                std::cout<<"Enter amount: ";std::cin>>Amount;
                CurrentAccount->UpdateBalance(Amount, '-');
                break;
              }
              case 3: {
                std::cout<<"Balance: "<<CurrentAccount->GetBalance();
                break;
              }
              case 4: {
                // Stops the User Options loop
                LoggedIn = false;
              }
              default:
                break;
            }
            std::cout<<"\n#=====================================#\n";
          }
        }
        CurrentAccount = CurrentAccount->Next;
      }
    }
};
