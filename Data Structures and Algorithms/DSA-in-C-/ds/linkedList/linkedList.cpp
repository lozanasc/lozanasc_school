#include <iostream>

class linkedList {
	public:
		class Node {
			public:
			int item;
			class Node* next;
			Node(int data){
				item = data;
				next = NULL;
			}
		};
		
		class Node* head = NULL;
		class Node* last = NULL;
		
		void insert(int element){
			Node* new_node = new Node(element);
			if(head==NULL){
				head = last = new_node;
			}
			else{
				new_node->next = head;
				head = new_node;
			}
		}
			
		void remove(){
			if(head == last){ //Checks if there's only 1 item in the list left
				head = last = NULL; //if true then we assign it to null
				return;
			}
			else {
				Node* second = head->next;
				head->item = NULL;
				head = second;
			}
		}
		
		void print(){
			Node* current_node = head;
			std::cout<<"\n [List] = ";
			if(current_node==NULL){
				std::cout<<" is empty! ";
			}
			while(current_node!=NULL){
				std::cout<<"["<<current_node->item<<"] ";
				current_node = current_node->next;
			}
		}
		
};

int main() {
	linkedList list;
	bool inUse = true;
	int choice;
	std::cout<<"LinkedList in C++ by Sean Christian Lozana \n";
	while(inUse){
		std::cout<<"\n [1] Add [2] Remove [3] Print [4] Exit [5] cls \n : ";
		std::cin>>choice;
		switch(choice){
			case 1: {
				int insert;
				std::cout<<"Insert: ";std::cin>>insert;
				list.insert(insert);
				break;
			}
			case 2: {
				list.remove();
				break;
			}
			case 3: {
				list.print();
				break;
			}
			case 4: {
				inUse= false;
				break;
			}
			case 5: {
				system("cls");
				break;
			}
			default:
				std::cout<<"Invalid input! \n";
		}
	}
	return 0;
}