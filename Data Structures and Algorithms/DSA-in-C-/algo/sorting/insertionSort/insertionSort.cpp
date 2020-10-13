#include <iostream>

using std::swap;

bool isSorted(int arr[], int size){
  //Let's check if the array only has 1 element on it. if it is then its true
  //Same goes if the size is 0
  if(size == 1 || size == 0)
    return true;
  for(int i=1; i<size; i++)
    if(arr[i-1] < arr[i]) //Looks for unsorted pair in the array
      return false;   //If there is then it returns false

  return true;
}

//Prints array function
void print(int arr[], int size){
    for(int i=0; i<size; i++)
        std::cout<<"[ "<<arr[i]<<"] ";
}

//Insertion sort function
void insertionSort(int arr[], int size){
    int i,min,j;
    
    for(i=1; i<size; i++){
        min = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > min){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1]=min;
}
}

int main(){
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(array) / sizeof(array[0]);
    if(!isSorted(array,size)){
        std::cout<<"There's nothing to sort tho :) \n";
    }
    else
        insertionSort(array,size);

        print(array,size);

        return 0;
}