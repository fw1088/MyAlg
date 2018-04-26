#include<stdio.h>

int partition(int *array,int start ,int end){
    int position=start-1;
    int base = array[end];
    for(int index = start; index < end; index++){
        if(array[index] <= base) {
            position++;
            int tmp = array[position];
            array[position]  = array[index];
            array[index] = tmp; 
        }
    }
    int tmp = array[position+1];
    array[position+1] = array[end];
    array[end] = tmp;
    return position + 1;
}
void quickSort(int *array, int start, int end) {
    if(start < 0|| end < 0 || start >= end)return;
    int position = partition(array,start,end);
    quickSort(array,start,position-1);
    quickSort(array,position+1,end);
}

void print_array(int *array,int length){
    int index = 0;
    for(;index < length;index++) {
        printf("%d ",array[index]);
    }
    printf("\n");
}

int main(){
    int array[6] = {2,3,45,0,12,-10};
    quickSort(array,0,5);
    print_array(array,6);
}
