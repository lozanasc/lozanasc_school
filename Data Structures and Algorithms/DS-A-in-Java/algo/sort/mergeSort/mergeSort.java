import java.util.Scanner;

class mergeSort{

	void merge(int[] arr, int left, int mid, int right){
	int i, j, k; //These are for the loops
    int n1 = mid - left + 1; //lower array index reference
    int n2 =  right - mid; 	//upper array index reference
    int[] lowArr = new int[n1];	//lower temporary sub array
    int[] highArr = new int[n2]; //upper temporary sub array
    for (i = 0; i < n1; i++) //We take the lower elements in the array and paste them into the temporary lower sub array
        lowArr[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) //We take the upper elements in the array and paste them into the temporary upper sub array
        highArr[j] = arr[mid + 1+ j]; 
    i = 0; //Starting index for lower sub array
    j = 0; //Starting index for upper sub array
    k = left;
    while (i < n1 && j < n2) //We're basically traversing each sub-array in a linear fashion
    { 
        if (lowArr[i] <= highArr[j]) 
        { 
        	/*
			If the element at lowArr[i] is less than or equal to the element at highArr[j]
			We assign the element at lowArr[i] at arr[k] which is the main/real array then increment i
        	*/
            arr[k] = lowArr[i]; 
            i++; 
        } 
        else
        { 
        /*
		If the element at lowArr[i] is greater than the element at the highArr[j]
		We assign the element at highArr[i] at arr[k] which is the main/real array then increment j
        */
            arr[k] = highArr[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1) 
    { 
        arr[k] = lowArr[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = highArr[j]; 
        j++; 
        k++; 
    } 

	}

	void mergeSort(int[] arr, int left, int right){
		if(left < right){
			int mid = (left + right) / 2;
			mergeSort(arr, left, mid); 
        	mergeSort(arr, mid+1, right); 
  
        	merge(arr, left, mid, right); 
		}
	}

	boolean isSorted(int[] arr){
		if(arr.length == 1 || arr.length == 0)
			return true;
		for(int i=1; i<arr.length; i++) //Looks for unsorted pairs in a linear traversal fashion
			if(arr[i-1] < arr[i])
				return false;

		return true;
	}

	void print(int arr[]){
		for(int i=0; i<arr.length; i++)
			System.out.print("["+arr[i]+"] ");
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int size;
		System.out.print("Enter array size: ");
		size = input.nextInt();
		int[] array = new int[size];
		System.out.print("Enter ["+size+"] numbers: ");
		for(int i=0; i<size; i++)
			array[i] = input.nextInt();
		System.out.print("Array: ");
		new mergeSort().print(array);
		if(!new mergeSort().isSorted(array)){
		System.out.print("\n The array is already sorted!");
		}
		else{
		System.out.print("Sorted Array: ");
		new mergeSort().mergeSort(array,0,array.length-1);
		new mergeSort().print(array);
	}
	}
}