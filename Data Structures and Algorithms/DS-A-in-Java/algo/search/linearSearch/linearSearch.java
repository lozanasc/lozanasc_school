class linearSearch {

	/*Constructor that contains the algorithm
	@param key the value to be searched
	*/
	public linearSearch(int[] array, int key){
		boolean isFound = false;
		//i moves through every single index in the array
		for(int i=0;i<array.length;i++){
			if(array[i]==key){
				System.out.print("Key = "+key+" is found at index ["+i+"]\n");
				isFound = true;
			}
		}
		if(!isFound){
			System.out.print("Key was not in the array! \n");
		}
	}

	//Main driver function
	public static void main(String[] args){
		int arr[] = {1,2,3,4,5};
		new linearSearch(arr,10);
	}

}