class DynamicArray 
{
    public:
    DynamicArray(int size){
        array[size];
        this->arrSize = size;
    }
    void insert(int value){
        
        int newArray[getSize()];

        if(arrSize == count){
            newArray[count * 2];
        //Copy all the elements in Array to the new Array
        for(int i=0; i<count; i++)
            newArray[i] = array[i];


        }

        newArray[count++] = value;
    }

    void print(){
        for(int i=0; i<arrSize; i++)
            std::cout<<"["<<array[i]<<"] ";
    }
    int getSize(){
        return arrSize;
    }
    private:
    int count;
    int arrSize;
    int *array[];
};