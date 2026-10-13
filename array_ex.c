#include<stdio.h>
int main(){
    
int arr[3][2] = {
    {1,3},
    {5,7},
    {9,11}
};  
    printf("\nOriginal Matrix : \n");
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 2; col++) {
            printf("%d \t", arr[row][col]);
        }
        printf("\n");
    }

    for(int col = 0;col < 2;col++) {
        for(int row = 0; row <3; row++) {
            arr[col][row] = arr[row][col];
        }
    }
    printf("\nAfter transpose : \n");
    for(int row = 0; row < 2; row++) {
        for(int col = 0; col < 3; col++) {
            printf("%d\t", arr[row][col]);
        }
        printf("\n");
    }
return 0;

}