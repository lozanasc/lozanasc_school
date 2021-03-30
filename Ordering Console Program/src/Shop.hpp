#include <iostream>

class Shop {
public:
  class Transactions {
    int TransactionId;
    string Salesperson;
  public:

    Transaction* Next;

    Transactions(int Id, string Salesperson){
      this->TransactionId = Id;
      this->Salesperson = Salesperson;

      Next = NULL;
    }
  }
}
