/*
  Made by: Sean Christian  Lozana
  A Linked List that will act as the Automated Teller Machine that will store, add, delete Account Information
*/

// Dependency Imports
#include "Account.hpp"

// class List {
//
//   public:
// };

class Node {
  public:
    Account Info;
    Node* Next;

    void CreateAccount(Node** Head, Account NewAccount){
      // Allocating a new node in the List
      Node* NewNode = new Node();

      NewNode->Info = NewAccount;
      
    }
};
