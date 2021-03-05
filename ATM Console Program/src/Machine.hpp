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
      string Name;
      int Pin;
      double Balance, Deposit, Withdraw;
      public:
        Account* Next;
        /*
          Constructor that initializes a new object with:
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

        int GetPin(){
          return this->Pin;
        }
        string GetName(){
          return this->Name;
        }
        double GetBalance(){
          return this->Balance;
        }
    };

    // Allocates the headptr and points it to null as its initial state
    class Account* Head = NULL;
    // Allocates the Lastptr and points it to null as its initial state
    class Account* Last = NULL;

    void CreateAccount(string SetName, int SetPin, double InitialDeposit){
      Account* NewAccount = new Account(SetName, SetPin, InitialDeposit);
      Head == NULL ? Head = Last = NewAccount : NewAccount->Next = Head; Head = NewAccount;
    }

    void ShowAllAccounts(){
      Account* CurrentAccount = Head;
      if(CurrentAccount == NULL)  {
        std::cout<<"No account is registered \n";
        return;
      }
      while(CurrentAccount != NULL){
        std::cout<<"#=====================================#\n";
        std::cout<<"# User Information:                   #\n";
        std::cout<<"# Pin: "<<CurrentAccount->GetPin()<<"      #\n";
        std::cout<<"# Name: "<<CurrentAccount->GetName()<<"    #\n";
        std::cout<<"# Balance: "<<CurrentAccount->GetBalance()<<" #\n";
        std::cout<<"#=====================================#\n";
        CurrentAccount = CurrentAccount->Next;
      }
    };

};
