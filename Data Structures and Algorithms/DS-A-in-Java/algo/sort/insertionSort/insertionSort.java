import java.util.Scanner;

class insertionSort{
/*
Made by: Sean Christian Lozana
*/
	private boolean isSorted(int[] arr){
		//Checks if the size of the array are base-cases if its 0 or 1 then its a sorted case
		if(arr.length == 1 || arr.length == 0)
			return true;
		//Traverses the array in a linear fashion to check if there is an unsorted pair
		//If true then return false
		for(int i=1; i<arr.length; i++)
			if(arr[i] < arr[i+1])
				return false;
	//If the array doesn't have an unsorted pair then return true the array is sorted
		return true;
	}

	//Prints the array
	private void print(int[] arr){
		for(int i=0; i<arr.length; i++)
			System.out.print("["+arr[i]+"] ");
	}


	private void toInsertionSort(int[] arr){
		int i, min, j;
		for (i = 1; i < arr.length; i++) 
    {  
        min = arr[i]; //element at arr[i] gets assigned at min
        j = i - 1; 
        while (j >= 0 && arr[j] > min) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;
        }  
        arr[j + 1] = min;
    } 
	}

	public static void main(String[] args) {
	Scanner input = new Scanner(System.in);
	System.out.print("Enter array size: ");
	int size = input.nextInt();
	int[] array = new int[size];
	System.out.print("Enter ["+size+"] numbers: ");
	for(int i=0; i<array.length; i++)
		array[i] = input.nextInt();
	System.out.print("Unsorted array: ");
	new insertionSort().print(array);
	System.out.print("\nSorted array: ");
	new insertionSort().toInsertionSort(array);
	new insertionSort().print(array);
	}
}