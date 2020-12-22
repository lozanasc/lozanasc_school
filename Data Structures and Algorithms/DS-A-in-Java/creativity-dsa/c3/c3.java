class c3 {
	/*Made by: Sean Christian Lozana
	c3 -
	Write a Java method that takes an array containing the set of all integers in the
	range 1 to 52 and shuffles it into random order. Your method should output each
	possible order with equal probability. 
	[/]
*/	

	//Function responsible for generating random numbers with equal probability
	private void generateNum(int[] arr){
		int min = 1;
		int max = 52;
		int range = max - min + 1;
		for(int i=0; i<arr.length; i++){
			int rand = (int)(java.lang.Math.random() * range) + min;
			while(i != 0 && checkDuplicate(arr,rand))
				rand = (int)(java.lang.Math.random() * range) + min;

			arr[i] = rand;
		}
	}
	//Does a loop again through an array and makes sure that no value is duplicated
	private boolean checkDuplicate(int[] arr,int value){
		for(int i=1; i<arr.length; i++)
			if(arr[i] == value)
				return true;

	return false;
	}

	//Sorts the array (bubble sort) - very unoptimized
	private void sort(int[] arr){
		for(int i=0; i<arr.length - 1; i++)
			for(int j=0; j<arr.length-i-1; j++){
				if (arr[j] > arr[j+1]) 
                { 
                    // swaps arr[j+1] and arr[j] 
                    int temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
			}
	}

	//Main driver function
	public static void main(String[] args) {
		int[] array= new int[52];
		new c3().generateNum(array);
		for(int i=0; i<array.length; i++)
			System.out.print("Index = "+(i+1)+" ["+array[i]+"] \n");
		new c3().sort(array);
		for(int i=0; i<array.length; i++)
			System.out.print("Index = "+(i+1)+" ["+array[i]+"] \n");
	}
}