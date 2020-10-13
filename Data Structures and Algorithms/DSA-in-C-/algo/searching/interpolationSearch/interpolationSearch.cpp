#include <iostream>

using std::swap; //For us to be able to use the swap() func

/*
Assumptions:
Inputted array can be sorted or unsorted
*/

bool isSorted(int arr[], int size){
  if(size==1 || size==0)
    return true;

  for(int i=1; i<size; i++)
    if(arr[i-1] > arr[i])
      return false;

  return true;
}

void print(int arr[], int size){
  for(int i=0; i<size; i++)
    std::cout<<"["<<arr[i]<<"] ";
}

void toSort(int arr[], int size){
  for(int i=0; i<size-1; i++){
    for(int j=0; j<size-i-1; j++)
        if(arr[j+1] < arr[j])
          swap(arr[j+1], arr[j]);
  }
}

int interpolationSearch(int arr[], int size, int key, int left, int right){
     while(right>=left){
       int pos = left + (key-arr[left]) * (right - left) / (arr[left] - arr[right]);
       if(arr[pos]==key)
        return pos;
       if(arr[pos] < key)
       left = pos + 1;
       else
       right = pos - 1;
     }
  return -1;
}

void result(int res){
  if(res==-1)
    std::cout<<"The key was not found in the array! \n";
  else
    std::cout<<"The key was found at index ["<<res<<"] \n";
}

int main(int argc, char const *argv[]) {
  int size, toSearch;
  std::cout<<"Enter array size: ";std::cin>>size;
  int array[size];

  for(int i=0; i<size; i++){
    std::cout<<"Enter element in index ["<<i<<"] = ";std::cin>>array[i];
}
  if(!isSorted(array, size)){
    toSort(array, size);
    print(array,size);
    std::cout<<" [The array was not sorted!]\nEnter key to be searched = ";std::cin>>toSearch;
    int res = interpolationSearch(array,size,toSearch,0,size);
    result(res);
  }
  else {
    print(array,size);
    std::cout<<" [The array was sorted]\nEnter key to be searched = ";std::cin>>toSearch;
    int res = interpolationSearch(array,size,toSearch,0,size);
    result(res);
  }
  return 0;
}
