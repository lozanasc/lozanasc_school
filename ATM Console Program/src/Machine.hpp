/*
  Made by: Sean Christian  Lozana
  A Linked List that will act as the Automated Teller Machine that will store and add Account Information
  The following are added features:
  * Withdraw
  * Deposit
  * Log-in
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
        /*
          Balance Updater is invoked only if the User wants to Deposit/Withdraw
          A switch case is used to indicate which operation the User will do
          @params {Double} Amount is the amount to be added or to be subtracted
          @params {Char} Operator is used to indicate what operation will be done and is used in the switch
        */
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

    /*
      Creates a new node containing new Account Information
      @params {String} SetName -> Set's account user Name
      @param {Integer} SetPin -> Set's account Pin number
      @param {Double} InitialDeposit -> All account must have contain a balance
    */
    void CreateAccount(string SetName, int SetPin, double InitialDeposit){
      Account* NewAccount = new Account(SetName, SetPin, InitialDeposit);
      Head == NULL ? Head = NewAccount : NewAccount->Next = Head; Head = NewAccount;
    }
    /*
      Traverses the entire List if the inputted pin for Identification has duplicates in the List which is O(n)
      @params {Integer} PinCheck used to check if there's any duplicate in the List
    */
    bool AccountCheck(int PinCheck){
      Account* CurrentAccount = Head;
      if(CurrentAccount == NULL)
        return true;
      while(CurrentAccount != NULL){
        if(PinCheck == CurrentAccount->GetPin())
          return false;
        else
          return true;
      }
    }
    /*
      Login is used for Authentication making we're pointing at the right node
      @params {Integer} VerifyPin is used to check the instance var Pin
    */
    void Login(int VerifyPin){
      Account* CurrentAccount = Head;
      // Checks if the List has any registered Accounts if not then the function terminates
      if(CurrentAccount == NULL){
        std::cout<<"No account is registered \n";
        return;
      }
      // Traverses each node of the List runs at O(n) time
      while(CurrentAccount != NULL) {
        // Checks if we're pointing at the right node and getting the right information
        if(VerifyPin==CurrentAccount->GetPin()){
          int Choice;
          bool LoggedIn = true;
          std::cout<<"#=====================================#\n";
          std::cout<<"#   █   █ ██▀ █   ▄▀▀ ▄▀▄ █▄ ▄█ ██▀   #\n";
          std::cout<<"#   ▀▄▀▄▀ █▄▄ █▄▄ ▀▄▄ ▀▄▀ █ ▀ █ █▄▄   #\n";
          std::cout<<"#=====================================#\n";
          std::cout<<"# User Information:                   #\n";
          std::cout<<"#=====================================#\n";
          std::cout<<"Pin: "<<CurrentAccount->GetPin()<<"    \n";
          std::cout<<"Name: "<<CurrentAccount->GetName()<<"  \n";
          std::cout<<"Balance: "<<CurrentAccount->GetBalance()<<"\n";
          /*
            Persists the Log-in session using the LoggedIn bool above
            Will only break out of the Loop if the User chooses to Log-out
          */
          while(LoggedIn){
            std::cout<<"[USER OPTIONS] \n [1][Deposit] \n [2][Withdraw] \n [3][View Balance] \n [4][Log-out] \n CHOICE: ";
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
                // Stops the Log-in session
                LoggedIn = false;
              }
              default:
                break;
            }
            std::cout<<"\n#=====================================#\n";
          }
        }
        CurrentAccount = CurrentAccount->Next; //Proceeds to traverse the entire list if the condition above fails
      }
    }
};
