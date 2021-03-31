/*

*/

// Dependency Imports
#include <iostream>
#include "Clear.hpp"

class Sales {
public:
  class Log {
    int Id, Qty;
    string ItemName, Attendant, CustomerName, DTTransaction;
    double Price, Total;
  public:
    Log* Next;
    /*
      Constructor for initializing a data to be logged in the Sales list with the ff params:
      @params {int} Id for Identification
      @params {string} ItemName for Item Name and Identification
      @params {double} Price for Item pricing
      @params {string} DTTransaction is for the Date and Time of the Transaction to be included in the Logs
    */
    Log(int Id, string ItemName, double Price, string DTTransaction){
      this->Id = Id;
      this->ItemName = ItemName;
      this->Price = Price;
      this->DTTransaction = DTTransaction;
      Next = NULL;
    }

    /*
      Setter function for setting the Salesperson's name in the Transaction Log
      @params {string} Salesperson for Identification
    */
    void SetSalesperson(string Salesperson){
      this->Attendant = Salesperson;
    }

    /*
      Setter function for setting the Customer's name in the Transaction Log
      @params {string} CustomerName for Identification
    */
    void SetCustomer(string CustomerName){
      this->CustomerName = CustomerName;
    }

    // Getter function that returns the Salesperson's name
    string GetAttendant(){
      return this->Attendant;
    }
    // Getter function that returns the Customer's name
    string GetCustomer(){
      return this->CustomerName;
    }
  };

};
