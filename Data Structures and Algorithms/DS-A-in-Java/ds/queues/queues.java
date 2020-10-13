/*
Queues Implementation via LinkedList by Sean Christian Lozana
*/
import java.util.Scanner;

class queues{
	
	static Node head;
	static Node last;

	static class Node {
		Node next;
		int data;
		Node(int inputData){
			data = inputData;
			next = null;
		}
	}

	public static queues enqueue(queues queue, int data){
		Node new_node = new Node(data);
		if(queues.head == null)
			queues.head = queues.last = new_node;
		else {
			new_node.next = queues.head;
			queues.head = new_node;
		}
		
	return queue;
	}


	public static void dequeue(){
		Node previous = getPrevious(last);
		if(previous == null){ 
			System.out.print("There's nothing to pop!");
		}
		else {
		last = previous;
		last.next = null;
		}
	}

	public static Node getPrevious(Node node){
		Node current = head;
		while(current!=null){
			if(current.next == last){
				return current;
			}
			current = current.next;
		}
			return null;
	}

	public static void printQueue(){
		Node current = head;
		System.out.print("\nQueue = ");
		if(current==null){
			System.out.print(" [empty] ");
		}
		while(current!=null){
			System.out.print("["+current.data+"] ");
			current = current.next;
		}
		System.out.println();
	}

	public static void main(String[] args) {
		queues queue = new queues();
		Scanner input = new Scanner(System.in);
		boolean willUse = true;
		System.out.print("Queues Implementation with LinkedList my Sean Christian Lozana \n");
		try {
		while(willUse){
			queues.printQueue();
			System.out.print("[1] Enqueue \n[2] Dequeue \n[3] Exit \n : ");
			int choice = input.nextInt();
			switch(choice){
				case 1: {
					System.out.print("Enqueue : ");
					int toQueue = input.nextInt();
					queues.enqueue(queue, toQueue);
					break;
				}
				case 2: {
					queues.dequeue();
					break;
				}
				case 3: {
					willUse = false;
					break;
				}
				default:
				System.out.println("Invalid input!");
			}
		}
		return;
	}
	finally {
		input.close();
	}
}
}