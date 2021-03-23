/*
  Made by Sean Christian Lozana
*/


#include <iostream>
#include "Client.hpp"
#include "Clear.hpp"

using std::string;

// This class is responsible for storing on-going loan application
class Lending {
public:
  class Loan {

    int ApplicationId;
    double Principal, Interest, MonthlyInterest;
    string Name, Password;

  public:
    // Next pointer that will point to the next node
    Loan* Next;

    /*
      Constructor that will initialize the Loan application
      @params {integer} Id for Identification
      @params {string} Name for Identification and Authentication
      @params {string} Password for Identification and Authentication
    */
    Loan(int Id, string Name, string Password){
      this->ApplicationId = Id;
      this->Name = Name;
      this->Password = Password;
    }
    /*
      Sets Principal of the Loan or the total payable of the Client without the interest
      @params {double} Principe amount payable of the client excluding interest
    */
    void SetPrincipal(double Principal){
      this->Principal = Principal;
    }
    /*
      Sets interest of the total principal
      @params {double} Interest rate of the Loan
    */
    void SetInterest(double Interest){
      this->Interest = Interest;
    }
    /*
      Sets the monthly interest of the loan based on the overall interest rate
    */
    void SetMonthlyInterest(double MonthlyInterest){
      this->MonthlyInterest = MonthlyInterest;
    }
    // returns the Principal of the Applicant
    double GetPrincipal(){
      return this->Principal;
    }
    // returns the Interest of the Applicant
    double GetInterest(){
      return this->Interest;
    }
    // returns the monthly interest of the Applicant
    double GetMonthlyInterest(){
      return this->MonthlyInterest;
    }
    // returns the Name of the Applicant
    string GetName(){
      return this->Name;
    }
    string GetPassword(){
      return this->Password;
    }
    // returns the Id of the Applicant
    int GetLoanId(){
      return this->ApplicationId;
    }
  };

  // Loan class will also store a List of client
  Client Applicant;

  // Initial state of the List
  Loan* Head = NULL;

  /*
    Function that creates a new Loan object and inserting it into the List
    @params {integer} Id for Identification
    @params {string} Name for Identification and Authentication
    @params {string} Password for Identification and Authentication
  */
  void CreateApplication(int Id, string Name, string Password){
    Loan* NewApplication = new Loan(Id, Name, Password);
    Head == NULL ? Head = NewApplication : NewApplication->Next = Head; Head = NewApplication;
  }

  /*
     Function that handles Login authentication for the Lender
     @params {string} Name for Identification and Authentication
     @params {string} Password for Authentication
  */
  void Login(string Name, string Password){
    Loan* CurrentApplication = Head;

    if(CurrentApplication == NULL)
	return;

    while(CurrentApplication != NULL){
	     if(CurrentApplication->GetName() == Name && CurrentApplication->GetPassword() == Password){
    	  bool isLoggedIn = true;
    	  while(isLoggedIn){
    	  int Choice;
    	  std::cout<<" Lending Application Console Program \n";
    	  std::cout<<" [1] Approve a Loan Application \n";
    	  switch(Choice){
    	  	case 1:	{
    		// Approval of Application code block goes here
  		    break;
    	  	}
    		default:
    		  break;
    	  }
  	   }
    }
    CurrentApplication = CurrentApplication->Next;
  }
}
};
