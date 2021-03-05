/*
  Made by: Sean Christian Lozana
  Class ATM is responsible for the basic attributes and functions of an ATM machine
*/
#include <iostream>

using std::string;

class Account {
  // Pin for Account Verification
  int Pin;
  // Name for Account Identification
  string Name;
  /*
    *Balance to output Account Owner's existing balance
    *Deposit if the Account Owner wants to add to its balance
    *Withdraw if the Account Owner wants to grab money from its balance
  */
  double Balance, Deposit, Withdraw;
public:
  // Account Constructor that will initialize
  Account(int UserPin, string UserName, double UserBalance){
      this->Pin = UserPin;
      this->Name = UserName;
      this->Balance = UserBalance;
  }
  // A Deposit function that will return the sum of the added @param Amount to the instance variable Balance
  double ToDeposit(double Amount){return (Amount+this->Balance);}
  // The Withdraw function will return the difference of the subtracted @param Amount to the instance variable Balance
  double ToWithdraw(double Amount){return (Amount-this->Balance);}
  // Will return the balance instance variable
  double GetBalance(){return this->Balance;}
};
