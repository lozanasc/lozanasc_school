class bubbleSort{
	
	private void tobubbleSort(int arr[]){
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

	private void print(int arr[]){
		for(int i=0; i<arr.length; i++)
			System.out.print("[ "+arr[i]+" ] ");
	}

	private bubbleSort(){
		int[] arr = new int[]{5,4,3,2,1};
		System.out.print(" Unsorted array: \n");
		print(arr);
		tobubbleSort(arr);
		System.out.print("\n Sorted array: \n");
		print(arr);
	}
	public static void main(String[] args) {
		new bubbleSort();
	}
}