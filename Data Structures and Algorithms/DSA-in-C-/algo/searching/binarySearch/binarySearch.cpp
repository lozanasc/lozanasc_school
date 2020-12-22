#include <iostream>

using std::swap;

bool isSorted(int arr[], int size){
	if(size == 1 || size == 0)
					return true;

	for(int i=1; i<size; i++)
			if(arr[i-1] > arr[i])
					return false;

	return true;
}

void toSort(int arr[], int size){
			for(int i=0; i<size-1; i++) //Simple bubble sort implementation
				for(int j=0; j<size-i-1; j++)
					if(arr[j+1] < arr[j])
						swap(arr[j+1], arr[j]);
}

void print(int arr[],int size){
	for(int i=0; i<size; i++){
		std::cout<<"["<<arr[i]<<"] ";
	}
	std::cout<<"\n";
}

int binarySearch(int arr[], int key, int left, int right){
	while(right >= left){
		int mid = left + right - 1 / 2;
		if(arr[mid] == key)
			return mid;
		if(arr[mid] < key)
			left = mid + 1;
		else if(arr[mid] > key)
			right = mid - 1;
	}
	return -1;
}

void result(int res){
	if(res == -1)
		std::cout<<"The key is not found int he array \n";
	else
		std::cout<<"The key is found at index ["<<res<<"] \n";
}

int main(int argc, char** argv) {
	int arr[10] = {2,1,3,4,5,6,7,8,9,10};
	int size = sizeof(arr) / sizeof(arr[0]);
	print(arr,size);
	if(!isSorted(arr,size)){
		std::cout<<"The inputtued array is not sorted. \n";
		toSort(arr, size);
		print(arr,size);
		int res = binarySearch(arr,8,0,size - 1);
		result(res);
	}
	else{
		std::cout<<"The inputtued array is sorted. \n";
		int res = binarySearch(arr,8,0,size - 1);
		result(res);
	}
	return 0;
}
