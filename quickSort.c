#include<stdio.h>
//quick sort

void printf_array(int *array, int length)
{
    int index = 0;
    for(; index < length; index++)
    {
        printf("%d ",array[index]);
    }
    printf("\n");
}

void quickSort(int *array, int length)
{
    int start = 0;
    int end = length -1;
    int value = array[0];
    if(length < 1) return;
    while(start < end) {
        while(start < end){
            if(array[end--] < value) {
                array[start++] = array[++end];
                break;
            }
        }
       while(start < end) {
           if(array[start++] > value){
               array[end--] = array[--start];
               break;
            }
        }
    }
    array[start] = value;
    quickSort(array,start);
    quickSort(array + start + 1,length - 1 - start);
}

int main(){
    int array[9] = {111,1,2,3,45,30,1,22,0};
    quickSort(array,9);
    printf_array(array,9);
    return 0;
}
