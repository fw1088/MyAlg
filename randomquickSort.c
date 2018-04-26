#include<stdio.h>

void print_array(int *array,int length){
    int index = 0;
    for(;index < length; index++){
        printf("%d ",array[index]);
    }
    printf("\n");
}

int partion(int* array,int start,int end){
    int pos = start - 1;
    int base = array[end];
    for(int index = start; index < end; index++){
        if(array[index]<base){
            pos++;
            int tmp = array[index];
            array[index] = array[pos];
            array[pos] = tmp;
         }
    }
    int tmp = array[pos+1];
    array[pos+1] = base;
    array[end] = tmp;
    return pos+1;
}
void quickSort(int *array,int start,int end){
    if(start<0||end<0||start>end) return;
    int pos = partion(array,start,end);
    quickSort(array,start,pos-1);
    quickSort(array,pos+1,end);
}

int main(){
    int array[6] = {1,23,1,1,33,2};
    quickSort(array,0,5);
    print_array(array,6);
    return 0;
}
