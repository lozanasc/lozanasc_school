/*
  Made by: Sean Christian Lozana
*/

// Dependency imports
#include <iostream>
#include "Clear.hpp"

using std::string;

class Inventory {
public:
  class Item {
  int Id, Qty;
  double Price;
  string Name, Type;
  public:
    Item* Next;

    /*
      Constructor for initializing an Item in the Inventory list with the ff params:
      @params {int} Id for Identification
      @params {int} Qty for Item quantity
      @params {double} Price for Item pricing
      @params {string} Name for Item Name and Identification
      @params {string} Type for Identifying the Type of Food the Item is
    */
    Item(int Id, int Qty, double Price, string Name, string Type){
      this->Id = Id;
      this->Qty = Qty;
      this->Price = Price;
      this->Name = Name;
      this->Type = Type;
      // Pointing Next pointer to NULL
      Next = NULL;
    }

    // returns the Item's Id
    int GetId(){
      return this->Id;
    }
    // returns the Item's availability via Quantity
    int GetQty(){
      return this->Qty;
    }
    // returns the Item's price
    double GetPrice(){
      return this->Price;
    }
    // returns the Item's name
    string GetItemName(){
      return this->Name;
    }
    // returns the Item's type
    string GetItemType(){
      return this->Type;
    }
  };

  // Initial state of the Inventory List
  Item* Head = NULL;


  /*
    Function responsible for adding new Items in the Inventory List
    @params {int} Id for Identification
    @params {int} Qty for Item quantity
    @params {double} Price for Item pricing
    @params {string} Name for Item Name and Identification
    @params {string} Type for Identifying the Type of Food the Item is
  */
  void AddItem(int Id, int Qty, double Price, string Name, string Type){
    Item* NewItem = new Item(Id, Qty, Price, Name,Type);
    Head == NULL ? Head = NewItem : NewItem->Next = Head; Head = NewItem;
  }

  /*
    Function responsible for outputting all Items in a List form available or not
  */
  void ViewItems(){
    clear();
    Item* CurrentItem = Head;

    if(CurrentItem==NULL)
      return;
    std::cout<<"[===================================]\n";
    std::cout<<"[           Inventory List          ]\n";
    std::cout<<"[===================================]\n";
    while(CurrentItem!=NULL){
      std::cout<<"[Item Availability] : "<<(CurrentItem->GetQty() > 0 ? "Available" : "Unavailable")<<"\n";
      std::cout<<"[Item Id] : "<<CurrentItem->GetId()<<"\n";
      std::cout<<"[Item Name] : "<<CurrentItem->GetItemName()<<"\n";
      std::cout<<"[Item Price] : "<<CurrentItem->GetPrice()<<"\n";
      std::cout<<"[Item Type] : "<<CurrentItem->GetItemType()<<"\n";
      std::cout<<"[Item Quantity] : "<<CurrentItem->GetQty()<<"\n";
      std::cout<<"[___________________________________]\n\n";

      CurrentItem = CurrentItem->Next;
    }
    std::cout<<"[===================================]\n";
  }

  /*
    Function responsible for outputting all available Items in a List form
  */
  void ViewAvailableItems(){
    Item* CurrentItem = Head;

    if(CurrentItem==NULL)
      return;
    std::cout<<"[===================================]\n";
    std::cout<<"[          Available Items          ]\n";
    std::cout<<"[===================================]\n";
    while(CurrentItem!=NULL){
      if(CurrentItem->GetQty() > 0){
        std::cout<<"[Item Id] : "<<CurrentItem->GetId()<<"\n";
        std::cout<<"[Item Name] : "<<CurrentItem->GetItemName()<<"\n";
        std::cout<<"[Item Price] : "<<CurrentItem->GetPrice()<<"\n";
        std::cout<<"[Item Type] : "<<CurrentItem->GetItemType()<<"\n";
        std::cout<<"[Item Quantity] : "<<CurrentItem->GetQty()<<"\n";
        std::cout<<"[___________________________________]\n\n";
      }
      CurrentItem = CurrentItem->Next;
    }
    std::cout<<"[===================================]\n";
  }
};
