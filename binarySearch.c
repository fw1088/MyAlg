#include<stdio.h>

int binarySearch(int* array,int length,int val){
    if(array ==  NULL || length < 1) return -1;
    int low = 0;
    int high = length -1;
    while(low < high ){
        int middle = (low+high)/2;
        if(array[middle] == val){
            return middle;   
        } else if(array[middle]< val){
           low = middle+1;
        } else if(array[middle] > val){
           high = middle -1;
        }
    }
    return -1;
}


int main(){
    int array[4] = {0,0,4,0};
    int index = binarySearch(array,4,4);
    printf("%d",index);
    return 0;
}
