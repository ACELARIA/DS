#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array1;
    int* array2;
} StructOfPointers;

void ReadArrayInput(StructOfPointers* arrays, int n) {
    printf("Enter elements for the first array:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the %d th element for the first array:\n", i + 1);
        scanf("%d", arrays->array1 + i); 
    }
}

void UpdateArray(StructOfPointers* arrays, int n){
    for(int i=0;i<n;i++){
        *(arrays->array2+i)=*(arrays->array1+i);
       if (i % 2 != 0 && i < n - 1){
        *(arrays->array2+i)=(*(arrays->array1+i-1))*(*(arrays->array1+i+1));
        }
        
    }
}
void printArray(int* array, int n){
    for(int i=0;i<n;i++){
        printf("%d",*(array+i));
    }
    printf("\n");
}


int main(){
    int n;

printf("enter size of array:");
scanf("%d",&n);

StructOfPointers* arrays;
arrays = (StructOfPointers*)malloc(sizeof(StructOfPointers));
if (arrays == NULL) {
        printf("Memory allocation for structure failed.\n");
        return 1;
    }
arrays->array1 = (int*)malloc(sizeof(int) * n);
arrays->array2 = (int*)malloc(sizeof(int) * n);
if (arrays->array1 == NULL || arrays->array2==NULL) {
        printf("Memory allocation for array failed.\n");
        return 1;
    }
    ReadArrayInput(arrays, n);

    UpdateArray(arrays, n);

    printf("Original array:\n");
    printArray(arrays->array1, n);

    printf("Modified array:\n");
    printArray(arrays->array2, n);

    free(arrays->array1);
    free(arrays->array2);
    free(arrays);
    return 0;
}