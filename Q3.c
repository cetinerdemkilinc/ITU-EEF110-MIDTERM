#include <stdio.h>

double findMinMax(double *arr, int numElements, int isMin){
    double min = __DBL_MAX__, max = __DBL_MIN__;
    for(int i=0; i<numElements; i++){
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    return (isMin==1 ? min : max);
}

int main(){

    double array[] = {4,6543,6,4,3254,53,453,5,465,675,7,564635,46345,6356,46,4356,54,64};

    printf("max: %g min: %g\n", findMinMax(array, sizeof(array)/sizeof(array[0]), 0), findMinMax(array, sizeof(array)/sizeof(array[0]), 1));

    return 0;
}