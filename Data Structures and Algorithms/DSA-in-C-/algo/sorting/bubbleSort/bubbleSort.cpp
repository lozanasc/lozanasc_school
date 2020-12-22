#include <iostream>

using std::swap;

void print(int arr[],int size){
  for(int i=0; i<size; i++)
    std::cout<<"["<<arr[i]<<"] ";
std::cout<<"\n";
}

void bubbleSort(int arr[], int size){
  for(int i=0; i<size-1; i++)
    for(int j=0; j<size-i-1; j++)
      if(arr[j+1] < arr[j])
          swap(arr[j+1],arr[j]);
  print(arr,size);
}

int main(int argc, char const *argv[]) {
  int arr[4] = {4,1,3,2};
  int size = sizeof(arr)/sizeof(arr[0]);
  bubbleSort(arr, size);
  return 0;
}
