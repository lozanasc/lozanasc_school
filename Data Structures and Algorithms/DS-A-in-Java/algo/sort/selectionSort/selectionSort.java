class selectionSort {
	
	/*
	The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

	1) The subarray which is already sorted.
	2) Remaining subarray which is unsorted.

	In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
	*/

	private void toSelectionSort(int[] arr){
		int i,j,min;

		for(i=0; i<arr.length-1; i++){
			min = i;
			for(j=i+1; j<arr.length; j++){
				if(arr[min] > arr[j]){
					int temp = arr[min];
					arr[min] = arr[j];
					arr[j] = temp;
			}
				}
	}
}

	private void print(int arr[]){
		for(int i=0; i<arr.length; i++)
			System.out.print("["+arr[i]+"] ");
	}

	public static void main(String[] args) {
	int[] array = new int[]{5,4,3,2,1};	
	System.out.print("Unsorted Array: \n");
	new selectionSort().print(array);
	System.out.print("\nSorted array via Selection sort \n");
	new selectionSort().toSelectionSort(array);
	new selectionSort().print(array);
	}
		
}