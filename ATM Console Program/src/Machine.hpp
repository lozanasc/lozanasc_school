/*
  Made by: Sean Christian  Lozana
  A Linked List that will act as the Automated Teller Machine that will store, add, delete Account Information
*/

// Dependency Imports
#include "Account.hpp"

class Machine {
  public:
  class Node {
      public:
        Account Info;
        Node* Next;
        // Constructor that initializes the new
        Node(Account NewAccount){
          this->Info = NewAccount;
          Next = NULL;
        }

    };

    // Allocates the headptr and points it to null as its initial state
    class Node* Head = NULL;
    // Allocates the Lastptr and points it to null as its initial state
    class Node* Last = NULL;

    void CreateAccount(Account NewAccount){

    }


}
