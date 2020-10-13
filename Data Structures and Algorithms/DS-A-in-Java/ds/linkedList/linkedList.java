import java.util.Scanner;

public class linkedList {

private class Node {
	private final int item;
	private Node next;

	public Node(final int element){
		this.item = element;
	}
}
	private Node first;
	private Node last;

	private void addLast(final int element){
		final Node node = new Node(element);
		if(isEmpty())
			first = last = node;
		else {
			last.next = node;
			last = node;
		}
	}

	private void removeFirst(){
		if(isEmpty())
			System.out.print("No such element!");

		if(first==last){ //If there's only 1 item in the list
			first = last = null;
			return;
		}

		final Node second = first.next; //Preserves the pointer pointing to the 2nd node
		first.next = null;	//Erases the pointer pointing to the 2nd node
		first = second;	//Replacing the 1st node to 2nd node
	}

	private void removeLast(){
		final Node previous = getPrevious(last);
		if(previous==null){
			System.out.print("No such element exist!");
		}
		else{
		last = previous;
		last.next = null;
		}
	}

	private Node getPrevious(final Node node){
			Node current = first;
		while(current!=null){
			if(current.next==last)
			{
				return current;
			}
			current = current.next;
		}
		return null;
	}

	private void addFirst(final int element){
		final Node node = new Node(element);
		if(isEmpty())
			first = last = node;
		else{
			node.next = first;
			first = node;
		}
	}
	private boolean isEmpty(){
		return first == null;
	}
	
	private boolean contains(final int element){
			return indexOf(element)!=-1;
	}

	private int indexOf(final int element){
		int index = 0;
		Node current = first;
		while(current!=null){
			if(current.item == element){
				return index;
			}
			current = current.next;
			index++;
		}
		return -1;
	}

	private void print(){
		Node current = first;
		System.out.print("\n[List] = ");
		if(current==null){
			System.out.print(" [Empty]");
		}
		while(current!=null){
			System.out.print("["+current.item+"] ");
			current = current.next;
		}
		System.out.println();
	}

	public static void main(final String[] args) {
		linkedList ll = new linkedList();
		Scanner input = new Scanner(System.in);
		boolean inUse = true;
		System.out.print("LinkedList Java Implementation by Sean Christian Lozana\n");
		try{
			while(inUse){
				ll.print();
				System.out.print(" [1] Insert(First)\n [2] Insert(Last)\n [3] Remove(First)\n [4] Remove(Last)\n [5] Search\n [6] Exit\n : ");
				int choice = input.nextInt();
				switch(choice){
					case 1: {
						System.out.print("Insert : ");
						int toInsert = input.nextInt();
						ll.addFirst(toInsert);
						break;
					}
					case 2: {
						System.out.print("Insert : ");
						int toInsert = input.nextInt();
						ll.addLast(toInsert);
						break;
					}
					case 3: {
						ll.removeFirst();
						break;
					}
					case 4:{
						ll.removeLast();
						break;
					}
					case 5:{
						System.out.print("Check if a value exist in the list \n value : ");
						int toSearch = input.nextInt();
						if(ll.contains(toSearch)){
						System.out.println("Searched value is present in the list!");
						}
						else
						System.out.println("Searched value is not present in the list!");
						break;
					}
					case 6:{
						inUse = false;
						break;
					}
					default:
						System.out.println("Invalid input!");
				}
			}
		}
		finally {
			input.close();
		}
}
}