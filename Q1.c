#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapHalves(int *arr, int numElements){
    for(int i=0; i<numElements/2; i++)
        swap(arr+i, arr+i+(numElements%2==0 ? numElements/2 : numElements/2+1));
}

int main(){
    int array[] = {1,2,3,4,5,6,7,8,9,10,11};

    swapHalves(array, sizeof(array)/sizeof(array[0]));

    for(int i=0; i<sizeof(array)/sizeof(array[0]); i++){
        printf("%d ", array[i]);
    }
    
    return 0;
}