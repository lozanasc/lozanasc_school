class jumpSearch{
	
	/*
Let’s consider the following array: (0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610). Length of the array is 16. 
Jump search will find the value of 55 with the following steps assuming that the block size to be jumped is 4.
STEP 1: Jump from index 0 to index 4;
STEP 2: Jump from index 4 to index 8;
STEP 3: Jump from index 8 to index 12;
STEP 4: Since the element at index 12 is greater than 55 we will jump back a step to come to index 8.
STEP 5: Perform linear search from index 8 to get the element 55.
	*/
// Assumptions:
// The inputted array can be sorted or unsorted
// Check if the array is sorted or not
// if sorted proceed if not sort it first

	boolean isSorted(int arr[]){
		if(arr.length == 1 || arr.length == 0){
			return true;
		}
		for(int i=1; i<arr.length; i++){
			if(arr[i-1] > arr[i])
				return false;
		}
		return true;
	}

	int toJumpSearch(int[] arr, int size, int key){
		int jump = (int)Math.floor(Math.sqrt(size)); //To get the jump we get the sqrt of the size
		int previous = 0;
        while (arr[Math.min(jump, size)-1] < key) 
        { 
            previous = jump; //Setting the previous jumped index
            jump += (int)Math.floor(Math.sqrt(size)); //Incrementing the jump by the sqrt of size
            if (previous >= size) //If the previous is already > or = to the array size
                return -1; 		 //that means the element is not found so we exit
        } 
        while (arr[previous] < key) 
        { 
            previous++; //This is basically a linear search
  
            
            if (previous == Math.min(jump, size)) //If the previous is = to the minimum of either 
                return -1; 						 //jump or size that means element is ot found
        } 

		if(arr[previous] == key)
			return previous;

		return -1;
	}

	void bubbleSort(int arr[]){
		for(int i=0; i<arr.length-1; i++){
			for(int j=0; j<arr.length-i-1; j++)
				if(arr[j+1] < arr[j]){
					int temp = arr[j+1];
					arr[j+1] = arr[j];
					arr[j] = temp;
				}
		}
	}

	void result(int res){
		if(res==-1)
			System.out.print("Key searched is not found in the array! \n");
		else
			System.out.print("The key is found at index ["+res+"] \n");
	}

	public static void main(String[] args) {
		int arr[] = new int[]{2,1,4,3,6,5,8,7};
		if(!new jumpSearch().isSorted(arr)){
			System.out.print("The array is unsorted, sorting... \n");
			new jumpSearch().bubbleSort(arr);
			int result = new jumpSearch().toJumpSearch(arr, arr.length, 5);
			new jumpSearch().result(result);
		}
		else{
		System.out.print("The array is sorted already \n");
		int result = new jumpSearch().toJumpSearch(arr, arr.length, 5);
		new jumpSearch().result(result);
	}
	}
}