class stacks{
	
	class Node{
		int value;
		Node next;
		Node(int data){
			value  = data;
			next = null;
		}
	}
	
	Node floor;

	private void push(int data){
		Node new_node = new Node(data);
		
		if(floor==null){
			floor = new_node;
		}
		else{
			new_node.next = floor;
			floor = new_node;
		}
	}

	private void pop(){
		if(floor == null){
			System.out.println("The stack is empty!");
		}
		else {
			Node prev = floor.next;
			floor.next = null;
			floor = prev;
		}
	}

	private void printStack(){
		Node current = floor;
		while(current!=null){
			System.out.print("[   "+current.value+"   ]\n");

			current = current.next;
		}
	}
	
	public static void main(String[] args) {
		stacks stack = new stacks();
		stack.push(1);
		stack.push(2);
		stack.pop();
		stack.printStack();
	}
}