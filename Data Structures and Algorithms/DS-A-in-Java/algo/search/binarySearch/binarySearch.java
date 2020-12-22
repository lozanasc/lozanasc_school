import java.util.Scanner;

class binarySearch{
	/*
	We basically ignore half of the elements just after one comparison.
	Compare x with the middle element.
	If x matches with middle element, we return the mid index.
	Else If x is greater than the mid element, then x can only lie in right half subarray after the mid element. So we recur for right half.
	Else (x is smaller) recur for the left half.
	*/

	/*Bubble sort
	if the array is unsorted.
	this isn't the best sorting algorithm but it works lol
	*/

	private boolean isSorted(int arr[]){
		if(arr.length==1 || arr.length==0)
			return true;
		for(int i=1; i<arr.length; i++){
			if(arr[i-1] > arr[i])
				return false;
		}
		return true;
	}

	private void bubbleSort(int arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j] > arr[j+1]) 
                { 
                    // swaps arr[j+1] and arr[j] 
                    int temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
    }

	private void print(int[] array){ //Prints out the array
		for(int i=0; i<array.length; i++)
			System.out.print("["+array[i]+"] ");
        
        System.out.println();
	}

	private int tobinarySearch(int[] array, int key, int left, int right){
		while(right >= left){
			int mid = left + (right - left) / 2;
			if(array[mid] == key) //Checks if the mid element is the same as the given key
				return mid;
			else if(array[mid] < key)	//If not and if the mid element is less than the key we go to the left side
				left = mid + 1;
			else if(array[mid] > key)	//If the mid element is greater than the key then we go to the right side
				right = mid - 1;
		}
		return -1;
}

	private void testRun(){
		Scanner input = new Scanner(System.in);
		System.out.print("Input array size: ");
		try {
			int size = input.nextInt();
			int[] array = new int[size];
			System.out.print("Enter ("+size+") elements: ");
			for(int i=0; i<array.length; i++)
				array[i] = input.nextInt();
			if(isSorted(array)){
				System.out.print("\n[Array is sorted!]\n");
                print(array);
                System.out.print("\nEnter value to be searched: ");
				int search = input.nextInt();
				int res = tobinarySearch(array, search, 0, array.length-1);
				if(res==-1) {
					System.out.print("Key searched is not found in the array! \n");
				}
				else
					System.out.print("The key is found at index "+res+"\n");
			}
			else{
				bubbleSort(array);
				System.out.print("\n[Array is not sorted!]\n");
                print(array);
                System.out.print("\nEnter value to be searched: ");
				int search = input.nextInt();
				int res = tobinarySearch(array, search, 0, size);
				if(res==-1) {
					System.out.print("Key searched is not found in the array! \n");
				}
				else
					System.out.print("The key is found at index "+res+"\n");
			}
			}
		finally {
			input.close();
		}


	}

	public static void main(String[] args) {
		new binarySearch().testRun();
	}
}