#include <iostream>

using std::swap;

bool isSorted(int array[], int size){
    if(size == 1 || size < 0)
        return true;

    for(int i=1; i<size; i++)
        if(array[i-1] > array[i])
            return false;
    
    return true;
}

void print(int array[], int size){
    for(int i=0; i<size; i++)
        std::cout<<"[ "<<array[i] <<" ] ";
}

void sort(int array[], int size){
    for(int i=0; i<size-1; i++)
        for(int j=0; j<size-i-1; j++)
            if(array[j] > array[j+1])
                swap(array[j],array[j+1]);
}

int ternarySearch(int array[], int size, int search, int left, int right){
    /*
     mid1 = l + (r-l)/3
     mid2 = r – (r-l)/3
     -First, we compare the key with the element at mid1. If found equal, we return mid1.
     -If not, then we compare the key with the element at mid2. If found equal, we return mid2.
     -If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
     -If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
     -If not, then we recur to the second (middle) part.
     */
    while(right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if(array[mid1] == search)
            return mid1;
        else if(array[mid2] == search)
            return mid2;
        else if (search < array[mid1])
            return ternarySearch(array,size,search,left,mid1 - 1);
        else if (search > array[mid2])
            return ternarySearch(array,size,search,mid2 + 1,right);
        else    
            return ternarySearch(array,size,search,mid1 + 1,mid2-1);
    }

    return -1;
}


int main(){
    int testArray[5] = {5,4,3,2,1};
    int size = sizeof(testArray) / sizeof(testArray[0]);

    if(isSorted(testArray,size)){
        std::cout<<"Array is sorted! \n";
        print(testArray,size);
        std::cout<<"\n Index found at = "<<ternarySearch(testArray,size,3,0,size - 1)<<"\n";
    }

    else{
        std::cout<<"Array is unsorted! \n";
        sort(testArray,size);
        print(testArray,size);
        std::cout<<"\n Index found at = "<<ternarySearch(testArray,size,3,0,size - 1)<<"\n";
    }
    
    return 0;
}