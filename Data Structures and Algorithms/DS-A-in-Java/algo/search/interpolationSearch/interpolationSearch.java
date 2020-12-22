

class interpolationSearch{

/*

The idea of formula is to return higher value of pos
when element to be searched is closer to arr[hi]. And
smaller value when closer to arr[lo]
pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]

arr[] ==> Array where elements need to be searched
x     ==> Element to be searched
lo    ==> Starting index in arr[]
hi    ==> Ending index in arr[]

Algorithm
Rest of the Interpolation algorithm is the same except the above partition logic.

Step1: In a loop, calculate the value of pos using the probe position formula.
Step2: If it is a match, return the index of the item, and exit.
Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise calculate the same in the right sub-array.
Step4: Repeat until a match is found or the sub-array reduces to zero.

*/
    //Check if the array is sorted or not
    boolean isSorted(int[] arr){
        if(arr.length == 1 || arr.length == 0)
            return true;

        for(int i=1; i<arr.length; i++){
            if(arr[i - 1] > arr[i])
                return false;
        }
        return true;
    }

    /*Bubble sort
	if the array is unsorted.
	this isn't the best sorting algorithm but it works lol
	*/
	 void bubbleSort(int arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j] > arr[j+1]) 
                { 
                    // swaps arr[j+1] and arr[i] 
                    int temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
    }

	private void print(int[] array){ //Prints out the array
		for(int i=0; i<array.length; i++)
			System.out.print(array[i]+"\n");
	}

    private int toInterpolationSearch(int[] arr,int left, int right, int key){
        while(right >= left){
            //pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]
            int pos = left + (key-arr[left]) * (right - left) / (arr[right] - arr[left]);
            if(arr[pos] == key)
                return pos;
            if(arr[pos] < key)
                left = pos + 1;
            else
                right = pos - 1;
        }
        return -1;
    }
	
public static void main(String[] args) {
       int[] arr = new int[]{1,2,3,4,5,6,7,8,9,10};
       if(!new interpolationSearch().isSorted(arr)){
            System.out.print("Array is not sorted, sorting... \n");
            new interpolationSearch().bubbleSort(arr);
            int res = new interpolationSearch().toInterpolationSearch(arr,0,arr.length-1,8);
            if(res==-1)
            System.out.print("Key is not found in the array! ");
            else
            System.out.print("Key is found at index ["+res+"] \n");        
       }            
       else{
        System.out.print("Array is sorted already: \n");
       int res = new interpolationSearch().toInterpolationSearch(arr,0,arr.length-1,8);
       if(res==-1)
        System.out.print("Key is not found in the array! ");
       else
        System.out.print("Key is found at index ["+res+"] \n");
        }
}

}