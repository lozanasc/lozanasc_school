#include <iostream>

using std::swap;

    /*
	The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.

	1) The subarray which is already sorted.
	2) Remaining subarray which is unsorted.

	In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
    */

void print(int arr[], int size){
for(int i=0; i<size; i++)
    std::cout<<"["<<arr[i]<<"] ";
}

void selectionSort(int arr[], int size){

    int i,j,min;
    for(i=0; i<size-1; i++){
        min = i;
        for(j=i+1; j<size; j++){
            if(arr[min] > arr[j])
                swap(arr[min], arr[j]);
        }
        
    }
    
}

int main(int argc, char const *argv[]) {
    int array[5] = {5,3,1,4,2};
    int size = sizeof(array) / sizeof(array[0]);
    std::cout<<"Unsorted array: \n";
    print(array,size);
    selectionSort(array,size);
    std::cout<<"\nSorted array: \n";
    print(array,size);
  return 0;
}

