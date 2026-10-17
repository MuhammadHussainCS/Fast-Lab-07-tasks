#include<stdio.h>
#include<stdlib.h>
int main() {
    char name[20];
    printf("\nEnter the name : ");
    scanf("%19[A-Za-z]", name);

    int total_characters = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        printf("\nCharacter at index %d: %c", i,name[i]);
        total_characters++;
    }


    if(name[0] >= 'a' && name[0] <= 'z') {
        name[0] = name[0] - 32;
    }
    printf("\nTotal Characters stored : %d", total_characters);
    printf("\nFinal Name : %s", name); 

    printf("\nExplanation of Scanset");
    printf("\nA scanset allows us to specify which characters scanf() should accept from the user. For example, %19[A-Za-z] accepts uppercase and lowercase English letters and reads a maximum of 19 characters. When it encounters a character outside this set, such as a digit, space, or special symbol, it stops reading. That character and the remaining input are not included in the stored name.");


    printf("\nExplanation of Array Bounds");
    printf("\nThe character array name[20] occupies 20 bytes. A maximum of 19 visible characters can be stored safely because one additional byte is needed for the null terminator '\0', which marks the end of the string. If we use %[A-Za-z] without specifying a width, scanf() may write beyond the array's boundaries when the user enters too many characters. This causes undefined behavior, which may lead to memory corruption or a program crash. Therefore, %19[A-Za-z] limits the input and prevents this buffer overflow.");

    printf("\nExample Inputs");
    printf("\nAyesha123: The array stores Ayesha. Reading stops when 1 is encountered.");
    printf("\nali_khan: The array stores ali. Reading stops when _ is encountered.");
    printf("\nSara Ahmed: The array stores Sara. Reading stops when the space is encountered.");

    printf("\nThe program then converts the first lowercase letter to uppercase if necessary, counts the stored characters, and prints each character with its index.");
    return 0;
}
