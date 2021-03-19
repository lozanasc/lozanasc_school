/*
  Made by Sean Christian Lozana
*/

#include <iostream>

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
    User(int Id, string Name, string Username, string Password){
      this->Id = Id;
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
      this->ApprovalStatus ? std::cout<<"Approved" : std::cout<<"Pending" return;
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
  void CreateClientAccount(int Id, string Name, string Username, string Password){
    User* NewAccount = new User(Id, Name, Username, Password);
    Head == NULL ? Head = NewAccount : NewAccount->Next = Head; Head = NewAccount;
  }


};
