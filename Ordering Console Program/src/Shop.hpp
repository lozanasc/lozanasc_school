/*
  Made by: Sean Christian Lozana
*/

#include <iostream>
#include "Inventory.hpp"
#include "Sales.hpp"

using std::string;

/*
  This class is the main class of the program where Sales and Inventory classes
  are integrated, the Shop class is dependent on both.
*/
class Shop {
public:
  class Transactions {
    int TransactionId;
    string Salesperson, Username, Password;
  public:

    Transactions* Next;

    /*
      Constructor for Transaction intializations with the ff params:
      @params {int} Id for Identification
      @params {string} Salesperson for Identification
      @params {string} Username for Identification and Authentication
      @params {string} Password for Authentication
    */
    Transactions(int Id, string Salesperson, string Username, string Password){
      this->TransactionId = Id;
      this->Salesperson = Salesperson;
      this->Username = Username;
      this->Password = Password;
      // Pointing Next pointer to NULL
      Next = NULL;
    }

    // Getter function that will return the Salesperson attending the Customer
    string GetSalesperson(){
      return this->Salesperson;
    }

    // returns the Username of the Salesperson
    string GetUsername(){
      return this->Username;
    }
    // returns the Password of the Salesperson
    string GetPassword(){
      return this->Password;
    }
  };

  // Referrence for the List being Empty at its initial State
  Transactions* Head = NULL;
  // Will be used to store all Transaction happened in the system
  Sales TransactionLogs;
  // Will be used as the Lookup for all the available food/drinks the Shop has to offer
  Inventory MenuRef;

  /*
    Function responsible for adding a new salesperson in the Shop
    @params {int} Id for Identification
    @params {string} Salesperson for Identification
    @params {string} Username for Identification and Authentication
    @params {string} Password for Authentication
  */
  void CreateAccount(int Id, string Salesperson, string Username, string Password){
    Transactions* NewSalesperson = new Transactions(Id, Salesperson, Username, Password);
    Head == NULL ? Head = NewSalesperson : NewSalesperson->Next = Head; Head = NewSalesperson;
  }

  /*
    Function responsible for a Logon session of the Salesperson
  */
  void Login(string Username, string Password){
    Transactions* Account = Head;

    // Checks if there are any Account existing in the Shop in the first place if not will terminate
    if(Account == NULL)
      return;

    // Does a traversal in the List to find the Account using the key's Username and Password
    while(Account!=NULL){
      if(Account->GetUsername() == Username && Account->GetPassword() == Password){
        bool LogonSession = true;
        // Logon session loop this will keep the Salesperson to do transaction as long as the condition remains fulfilled
        while(LogonSession){
          int Choice;

          std::cout<<"[===================================]\n";
          std::cout<<"[ [1] New Transaction               ]\n";
          std::cout<<"[ [2] New Item                      ]\n";
          std::cout<<"[ [3] View Inventory                ]\n";
          std::cout<<"[ [4] Exit                          ]\n";
          std::cout<<"[===================================]\n";
          std::cout<<"[ Hello , "<<Account->GetSalesperson()<<" ]\n";
          std::cout<<"[ CHOICE ] ";std::cin>>Choice;
          switch(Choice){
            // This case is responsible for creating a new transaction
            case 1: {
              MenuRef.ViewAvailableItems();
              // Responsible for grabbing built-in feature from g++ compiler to get platform's DATE and TIME information
              string TransactionDate = (string) __DATE__;
              string TransactionTime = (string) __TIME__;
              // Concatenating Date and Time into one single variable
              string TransactionDT = TransactionDate + " " + TransactionTime;

              break;
            }
            case 2: {
              clear();
              int Id, Qty;
              string Name, Type;
              double Price;
              std::cout<<"[===================================]\n";
              std::cout<<"[          Adding of Item           ]\n";
              std::cout<<"[===================================]\n";
              std::cout<<"[Enter New Item Id] : ";std::cin>>Id;
              std::cout<<"[Enter New Item Name] : ";std::cin>>Name;
              std::cout<<"[Enter New Item Type] : ";std::cin>>Type;
              std::cout<<"[Enter New Item Price] : ";std::cin>>Price;
              std::cout<<"[Enter New Item Quantity] : ";std::cin>>Qty;
              MenuRef.AddItem(Id, Qty, Price, Name,Type);
              break;
            }
            // Terminates the session loop
            case 3: {
              MenuRef.ViewItems();
              break;
            }
            case 4: {
              LogonSession = false;
              break;
            }
            default:
              break;
          }
        }

        // Terminates prematurely and will not proceed to search the entire list
        return;
      }
      Account = Account->Next;
    }


  }


};
