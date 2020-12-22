//Dynamic array made by: Sean Christian Lozana
class arrays{

	private int[] arr;
	private int count;

	public arrays(int length){
		arr = new int[length];
	}

	public void insert(int element){
		if(arr.length == count) {
			int[] newArr = new int[count * 2];

			for(int i=0; i<count; i++)
				newArr[i] = arr[i];

			arr = newArr;
		}
		arr[count++] = element;
	}

	public int indexOf(int element){
		for(int i=0; i<count; i++)
			if(arr[i]==element)
				return i;

		return -1;
	}

	public void print(){
		for(int i=0; i<count; i++)
			System.out.print(arr[i]+"\n");
	}

	public void removeAt(int index){
		if(index >= count || index < 0)
			throw new IllegalArgumentException();
		else
			for(int i=index; i<count; i++)
				arr[i] = arr[i+1];
			
		count--;			
	}	
}