#include<stdio.h>
#include<stdbool.h>
int main(){
    bool runAgain = true;
    
    while(runAgain) {
        printf("\n============================================");
        printf("\nPhone Number Cleaner for a Customer Database");
        printf("\n============================================");
        char phoneNumber[30];
        
        printf("\nEnter Your Local Phone Number : ");
        if(scanf("%29[^\n]", phoneNumber) != 1) {
            printf("\nInvalid Input");
            getchar();
            continue;
        }

        getchar();

        char phoneNoFormatted[30];
        int index = 0;
        int count_digits = 0;

        for(int i = 0; phoneNumber[i] != '\0'; i++) {
            if(phoneNumber[i] >= '0' && phoneNumber[i] <= '9') {
                phoneNoFormatted[index] = phoneNumber[i];
                count_digits++;
                index++;
            } 
        }

        phoneNoFormatted[index] = '\0';
        printf("\nOriginal Inputted Number : %s", phoneNumber);
        printf("\nFormatted Phone Number   : %s", phoneNoFormatted);
        printf("\nCount of digits Found    : %d", count_digits);

        if(count_digits == 11) {
            printf("\nValid Local Number");
            runAgain = false;
        } else {
            printf("\nInvalid Lenght.Please re enter");
        }
    }
    // %[^\n] reads everything until Enter is pressed.
    // %[^-] reads everything until the first '-' is found.
    // The filtering loop copies only digits into the second array.
    // '\0' is added at the end to terminate the cleaned string.

    printf("\nSo %[^\\n] stops our string when we encounter the \\n in an inputted string");
    printf("\nSo if we we change it to %[^-] so wehn the inputs encounter - it will stop/break our string , leading to get only numbers that user enter before -");
    return 0;
}