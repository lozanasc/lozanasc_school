#include <iostream>
class doublyLinkedList{
  class Node{
    private:
      int data;
      Node* head;
      Node* next;
      Node* prev;
    public:
      Node(int value){
        this->data = value;
        next = prev = NULL;
      }
  };
};

int main(int argc, char const *argv[]) {

  return 0;
}
