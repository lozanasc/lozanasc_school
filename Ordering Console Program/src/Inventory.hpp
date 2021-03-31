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

      Next = NULL;
    }



  };

};
