class c2 {
	/*
	Made: by Sean Christian Lozana
	c2 -
	Write a Java method that takes an array of int values and determines if all the
	numbers are different from each other (that is, they are distinct). 
	[/]
	*/
	private c2(int[] arr){
		if(arr.length == 1 || arr.length == 0)
			System.out.print("There's nothing to compare!");
		for(int i=1; i<arr.length; i++)
			if(arr[i-1] != arr[i])
				System.out.print("Elements at index ["+(i-1)+"] and ["+i+"] is different! \n");
	}

	public static void main(String[] args) {
		int[] array = {1,1,2,3,4};
		for(int i=0; i<array.length; i++)
			System.out.print("["+array[i]+"] ");
		System.out.print("\n");
		new c2(array);
	}
}