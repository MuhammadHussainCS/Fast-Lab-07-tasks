// Scenario 1: Daily Temperature Monitoring Station
// Concepts covered: 1D arrays, initialization lists, sizeof length, for loops, modifying elements,
// memory addresses
// A small weather station in Karachi records the temperature in degrees Celsius once every
// day for a week, and the meteorological office wants a simple C program to summarize those
// readings. Write a program that declares an integer array of 7 elements and initializes it at
// declaration with the values 31, 33, 35, 34, 38, 36, and 32. Compute the array length using
// sizeof(array_name) / sizeof(array_name[0]) rather than hard-coding 7, so the program still
// works if the office later adds more days. Using a for loop, print each reading in the format
// &quot;Day 1: 31 C&quot;, remembering that the array index starts at 0 while the day numbers shown to
// the user start at 1.
// In the same or a second loop, calculate and display the highest temperature, the lowest
// temperature, and the average temperature for the week. A sensor fault is then discovered:
// the reading for the third day was wrongly logged and should be 37 instead of 35. Modify only
// that element directly by its index, then reprint the whole array and recompute the statistics to
// show how the change affects the results. Finally, print the memory address of each element
// using &amp;array[i] and explain, in a short comment, what the gaps between consecutive
// addresses reveal about contiguous memory storage.
#include<stdio.h>
int main(){
    int arr[] = {31,33,35,34,38,36,32};
    int no_of_elements = sizeof(arr) / sizeof(arr[0]);

    float sum1 = 0;
    float avg1 = 0;

    int maximum1 = arr[0];
    int minimum1 = arr[0];
    for(int i = 0; i < no_of_elements; i++) {
        printf("\nDay %d : %d C", i+1, arr[i]);
        sum1 = sum1 + arr[i];

        if(arr[i] > maximum1) {
            maximum1 = arr[i];
        }

        if(arr[i] < minimum1) {
            minimum1 = arr[i];
        }

    }

    avg1 = sum1 / no_of_elements;

    printf("\nMaximum Temperature this week : %d", maximum1);
    printf("\nMinimum Temperature this week : %d", minimum1);
    printf("\nAverage Temperature : %.2f", avg1);


    int maximum2 = arr[0];
    int minimum2 = arr[0];
    float sum2 = 0;
    float avg2 = 0;
    for(int i = 0; i < no_of_elements; i++) {
        if(i == 2) {
            arr[i] = 37;
        }

        printf("\nDay %d : %d C", i+1, arr[i]);
        sum2 = sum2 + arr[i];

        if(arr[i] > maximum2) {
            maximum2 = arr[i];
        }

        if(arr[i] < minimum2) {
            minimum2 = arr[i];
        }
    }

    avg2 = sum2 / no_of_elements;
    
    printf("\nMaximum Temperature this week : %d", maximum2);
    printf("\nMinimum Temperature this week : %d", minimum2);
    printf("\nAverage Temperature : %.2f", avg2);

    for(int i = 0; i < no_of_elements; i++) {
        printf("\n\n%d\t", &arr[i]);
    }
    printf("\n\nSince array is contigious block of memory so the very first element memory address has some address and with every other(next) element the memory address get +4 because each int contains 4 bytes");
    return 0;
}