#include <iostream>
/*
This search algorithm does not mind sorted or unsorted array inputs
*/
int linearSearch(int arr[], int key, int size){
	for(int i=0; i<size; i++){
		if(arr[i]==key){
			return i;
		}
	}
	return -1;
}

int main(int argc, char** argv) {

	int arr[5] = {1,2,3,4,5};
	int size = sizeof(arr) / sizeof(arr[0]);
	int res = linearSearch(arr,3,size);
	if(res==-1)
		std::cout<<"Key is not found in the array! \n";
		else
		std::cout<<"Key is found at index ["<<res<<"] \n";
		return 0;
}
