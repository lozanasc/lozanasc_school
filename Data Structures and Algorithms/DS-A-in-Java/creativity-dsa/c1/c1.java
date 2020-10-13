class c1 {
	/*
	Made by: Sean Christian Lozana
	c1-
		Write a short Java function that tkaes an array of integer values and 
		determines and if there is a pair of number in array whose product is odd

		[/]
	*/
	private c1(int[] arr){
		for(int i=1; i<arr.length; i++)
			if((arr[i-1] % arr[i]) != 0)
				System.out.print("Product of "+arr[i-1]+" and "+arr[i]+" is odd!\n");
	}

	public static void main(String[] args) {
		int[] array = {1,2,3,4,5};
		new c1(array);
	}
}