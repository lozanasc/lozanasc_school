public class ternarySearch {
    /*
    Ternary search is a divide and conquer algorithm that can be used to find an element in an array. 
    It is similar to binary search where we divide the array into two parts but in this algorithm. 
    In this, we divide the given array into three parts and determine which has the key (searched element). 
    We can divide the array into three parts by taking mid1 and mid2 which can be calculated as shown below. 
    Initially, l and r will be equal to 0 and n-1 respectively, where n is the length of the array.

    mid1 = l + (r-l)/3
    mid2 = r – (r-l)/3

    Note: Array needs to be sorted to perform ternary search on it.

    Steps to perform Ternary Search:

    -First, we compare the key with the element at mid1. If found equal, we return mid1.
    -If not, then we compare the key with the element at mid2. If found equal, we return mid2.
    -If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
    -If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
    -If not, then we recur to the second (middle) part.
    */
    
    private void print(int[] array){
        for(int i=0; i<array.length; i++)
            System.out.print("["+array[i]+"] ");
    }

    /*
    I wonder why this doesn't work?!??!
    private void swap(int a, int b){        
        int temp = a;
        a = b;
        b = temp;
    }*/

    private void sort(int[] array){
        for(int i=0; i<array.length-1; i++)
            for(int j=0; j<array.length-i-1; j++)
                if(array[j] > array[j+1]){
                        int temp = array[j];
                        array[j] = array[j+1];
                        array[j+1] = temp;
                    }
    }

    private boolean isSorted(int[] array){
        if(array.length == 1 || array.length < 0)
            return true;

        for(int i=1; i<array.length; i++)
            if(array[i-1] > array[i])
                return false;

        return true;
    }
    
    private int toTernarySearch(int[]array, int search, int left, int right){
     /*
     mid1 = l + (r-l)/3
     mid2 = r – (r-l)/3
     -First, we compare the key with the element at mid1. If found equal, we return mid1.
     -If not, then we compare the key with the element at mid2. If found equal, we return mid2.
     -If not, then we check whether the key is less than the element at mid1. If yes, then recur to the first part.
     -If not, then we check whether the key is greater than the element at mid2. If yes, then recur to the third part.
     -If not, then we recur to the second (middle) part.
     */
        while(right >= left){
            int mid1 = left + (right-left) / 3;
            int mid2 = right - (right-left) / 3;
            if(array[mid1] == search)
                return mid1;
            else if (array[mid2] == search)
                return mid2;
            else if (search < array[mid1])
            return toTernarySearch(array,search,left,mid1 - 1);
            else if(search > array[mid2])
            return toTernarySearch(array,search,mid2 + 1, right);
            else
                return toTernarySearch(array,search,mid1 + 1, mid2 - 1);
		}
        return -1;
    }
    
    public static void main(String[] args) {
        int[] testArray = new int[]{5,4,3,2,1};
        ternarySearch test = new ternarySearch();
        if(test.isSorted(testArray))
            System.out.print("sorted lol");
        else {
            test.sort(testArray);
            //Output is wrong lol
            System.out.print("Element found at index : "+test.toTernarySearch(testArray,5,0,testArray.length - 1)+"\n");
            test.print(testArray);
        }
        
    }
}