#include <iostream>
#include <cmath>

using std::swap;

/*
TODO:
isSorted();   [/]
toSort();     []
jumpSearch(); []
*/

int minimum(int num, int num2){
  int min;
  if(num < num2)
    min = num;
  else if(num2 < num)
    min = num2;
return min;
}

void print(int arr[], int size){
  for(int i=0; i<size; i++)
    std::cout<<"["<<arr[i]<<"] ";
}

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

void toSort(int arr[], int size){
  for(int i = 0; i<size-1; i++) //First loop that iterates till n-1
    for(int j = 0; j<size-i-1; j++) //Second loop that iterates till n-i-1
        if(arr[j+1] < arr[j])
          swap(arr[j+1] , arr[j]);
}

int jumpSearch(int arr[], int size, int key){
  int jump = (int)sqrt(size);
  int previous = 0;
  while(arr[minimum(jump, size) - 1] < key){
    previous = jump;
    jump += (int)sqrt(size);
    if (previous >= size) //If the previous is already > or = to the array size
                return -1; 		 //that means the element is not found so we exit
   while(arr[previous] < key){
     previous++; //This is basically a linear search
     if (previous == minimum(jump, size)) //If the previous is = to the minimum of either
                return -1; 						 //jump or size that means element is ot found
   }
  }
  if(arr[previous]==key)
    return previous;

  return -1;
}
void result(int res){
  if(res == -1)
    std::cout<<"Key is not found in the array! \n";
  else
    std::cout<<"The key is found at index ["<<res<<"] \n";
}
int main(int argc, char const *argv[]) {
  int size, toSearch;
  std::cout<<"Enter array size: ";std::cin>>size;
  int arr[size];
  for(int i=0; i<size; i++)
    std::cin>>arr[i];
  if(!isSorted(arr, size)){
    toSort(arr, size);
  print(arr, size);
  std::cout<<"[Array wasn't sorted!] \nSearch input: ";std::cin>>toSearch;
  int res = jumpSearch(arr, size, toSearch);
  result(res);
}
else{
  print(arr, size);
  std::cout<<"[Array was sorted!]\nSearch input: ";std::cin>>toSearch;
  int res = jumpSearch(arr, size, toSearch);
  result(res);
}  return 0;
}
