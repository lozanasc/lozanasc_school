/*
  Made by Sean Christian Lozana

  Complete this Project today:
  4-Session Pomodoro
  [X] Session 1
    [] Break 1
  [] Session 2
    [] Break 2
  [] Session 3
    [] Break 3
  [] Session 4
    [] Break 4

  Client should be able to do the ff:

  - Client should be able to loan an amount of no less than 3,000 PHP
  - Client should be able to choose how many months client is willing to pay

  Client Information should contain the ff:
    - Name
    - Amount Loaned
    - Principal with Interest
    - Monthly Payment
    - Approval Status
    - Loan Type
*/

// Dependency Imports
#include <iostream>
#include "Clear.hpp"

using std::string;

/*
  This class is responsible for storing User clients in a List
*/
class Client {
public:
  class User {

    int Id, MonthlyPlan;
    string Fullname, Username, Password, LoanType;
    double Loan, Balance, MonthlyPayment;
    bool ApprovalStatus;

  public:

    // Next pointer that will point to the next node
    User* Next;

    /*
      Constructor that will initialize a User Object with the ff parameters:
      @params {integer} Id for Identification
      @params {string} Name for Identification
      @params {string} Username for Identification and Authentication
      @params {string} Password for Authentication
    */
    User(int Id, int MonthsToPay, double Amount, string LoanType, string Name, string Username, string Password){
      this->Id = Id;
      this->MonthlyPlan = MonthsToPay;
      this->LoanType = LoanType;
      this->Loan = this->Balance = Amount;
      this->Fullname = Name;
      this->Username = Username;
      this->Password = Password;
    }

    /*
      Sets Client Loan value and will also be automatically added to your Balance
      @params {double} Amount value to be assigned for the Loan attribute
    */
    void SetLoan(double Amount){
      this->Loan = this->Balance = Amount;
    }

    // Returns the Client Loan amount
    double GetLoan(){
      return this->Loan;
    }

    // Returns client's Balance
    double GetBalance(){
      return this->Balance;
    }

    // Returns client's government name
    string GetFullname(){
      return this->Fullname;
    }

    // Returns client's account name
    string GetUsername(){
      return this->Username;
    }
    // Returns client's account password
    // Note: Please don't use this in your systems, this is very bad code for Authentication
    //**public access for your password? that's completely safe! ./src/trust/me/bro
    string GetPassword(){
      return this->Password;
    }

    /*
      Sets Loan Application status
      @params {bool} Status Application status indicator
    */
    void SetApprovalStatus(bool Status){
      this->ApprovalStatus = Status;
    }

    /*
      Getter function that will not actually return a boolean
      However will automatically output the status of your Application
      as a Message
    */
    void GetApprovalStatus(){
      this->ApprovalStatus ? std::cout<<"Approved" : std::cout<<"Pending"; return;
    }

    // Sets client's installment plan in Months
    void SetMonthlyPlan(int MonthsToPay){
      this->MonthlyPlan = MonthsToPay;
    }

    // Returns client's choice of Monthly payment plan
    int GetMonthlyPlan(){
      return this->MonthlyPlan;
    }

    // Substracts client's balance
    void Pay(int Amount){
      this->Balance -= Amount;
    }
    // Sets client's type of Loan
    void SetLoanType(string LoanType){
      this->LoanType = LoanType;
    }

    // Returns client's Loan type
    string GetLoanType(){
      return this->LoanType;
    }

  };

  // Initializing Head pointer with NULL as its initial state as indicator that the List is Empty
  User* Head = NULL;

  /*
    Function that creates a new User object and inserting it into the List
    @params {integer} Id for Account Identification
    @params {string} Name Fullname for Account Identification
    @params {string} Username for Account Identification and Authentication
    @params {string} Password for Account Authentication
  */
  void CreateClientAccount(int Id, int MonthsToPay, double Amount, string LoanType, string Name, string Username, string Password){
    User* NewAccount = new User(Id, MonthsToPay, Amount, LoanType, Name, Username, Password);
    Head == NULL ? Head = NewAccount : NewAccount->Next = Head; Head = NewAccount;
  }

  /*
    Function that outputs all the existing client information
  */
  void GetClientList(){
    User* CurrentUser = Head;

    if(CurrentUser == NULL)
      return;

    std::cout<<"<======================================>\n";
    std::cout<<"<    Client Information Master List    >\n";
    std::cout<<"<======================================>\n";
    while(CurrentUser!=NULL){
      std::cout<<"Fullname: ";CurrentUser->GetFullname();
      std::cout<<"\nBalance: ";CurrentUser->GetBalance();
      std::cout<<"\nMonths to Pay: ";CurrentUser->GetMonthlyPlan();
      std::cout<<"\nLoan Type: ";CurrentUser->GetLoanType();
      CurrentUser = CurrentUser->Next;
    }
  }

  /*
    Function responsible for Loggin in Client and giving them several features to do with their account
    @params {string} Username For Identification and Authentication
    @params {string} Password for Authentication

    NOTE:
    By now you're probably laughing at how inefficient the entire program is
  */
  void ClientLogin(string Username, string Password){

    User* CurrentUser = Head;

    // List is empty
    if(CurrentUser==NULL)
      return;

    // Traverses the entire list looking for the right inputted Username and Password
    while(CurrentUser!=NULL){
      // Verification logic
      if(CurrentUser->GetUsername() == Username && CurrentUser->GetPassword() == Password){
        // Main Logon session loop
        bool ClientSession = true;
        while(ClientSession){
            int Choice;
            std::cout<<"<=======================================>\n";
            std::cout<<"<   Client Login Session                >\n";
            std::cout<<"<   Made by: Sean Christian Lozana      >\n";
            std::cout<<"<                                       >\n";
            std::cout<<"<   <1> Check Application Status        >\n";
            std::cout<<"<   <2> Pay Monthly                     >\n";
            std::cout<<"<   <3> Check Balance                   >\n";
            std::cout<<"<   <4> Exit                            >\n";
            std::cout<<"<=======================================> \n";
            std::cout<<" <User in Session> -> ";CurrentUser->GetFullname();std::cout<<"\n";
            std::cout<<" [ CHOICE -> ] ";std::cin>>Choice;
            switch (Choice) {
              // Case that allows client to check their Loan application status
              case 1:{
                clear();
                std::cout<<"<======================================>\n";
                std::cout<<"<    Check Client Application Status   >\n";
                std::cout<<"<======================================>\n";
                std::cout<<" <Loan Application Status> -> ";CurrentUser->GetApprovalStatus();std::cout<<"\n";
                break;
              }
              // Case that allows client to pay their balance
              case 2: {
                clear();
                if(CurrentUser->GetBalance() <= 0 ){
                  std::cout<<"<======================================>\n";
                  std::cout<<"<         No on-going Loan Plan        >\n";
                  std::cout<<"<======================================>\n";
                }
                else {
                  double Amount;
                  std::cout<<" <Outstanding Balance> -> "<<CurrentUser->GetBalance()<<"\n";
                  std::cout<<" <Amount to Pay> -> ";std::cin>>Amount;
                  CurrentUser->Pay(Amount);
                }
                break;
              }
              case 3: {
                clear();
                std::cout<<"<======================================>\n";
                std::cout<<" <Outstanding Balance> -> "<<CurrentUser->GetBalance()<<"\n";
                std::cout<<"<======================================>\n";
                break;
              }
              // Exits the Client to the Login client session loop
              case 4: {
                ClientSession = false;
                break;
              }
              default:
                break;
            }
        }
        return;
      }
      CurrentUser = CurrentUser->Next;
    }
}

  void Approval(string Username){
    User* ClientToApprove = Head;
    if(ClientToApprove==NULL)
      return;
    while(ClientToApprove!=NULL){
      if(ClientToApprove->GetUsername() == Username){
        clear();
        string Choice;
        std::cout<<"Fullname: ";ClientToApprove->GetFullname();
        std::cout<<"\nBalance: ";ClientToApprove->GetBalance();
        std::cout<<"\nMonths to Pay: ";ClientToApprove->GetMonthlyPlan();
        std::cout<<"\nLoan Type: ";ClientToApprove->GetLoanType();
        std::cout<<" <Type Approve to Approve and Decline to Reject Application> \n";
        std::cout<<"  -> ";std::cin>>Choice;
        if(Choice == "Approve"){
          ClientToApprove->SetApprovalStatus(true);
        }
        else {
          ClientToApprove->SetApprovalStatus(false);
        }
        return;
      }
      ClientToApprove = ClientToApprove->Next;
    }
  }

};
