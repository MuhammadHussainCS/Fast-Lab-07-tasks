// Scenario 2: Student Marks Entry and Grade Report
// Concepts covered: float arrays, input loops, validation, conditional remarks, in-place update of all
// elements
// A teaching assistant at a university needs to process quiz marks for a section of 10 students,
// and doing this by hand with ten separate variables would be tedious and error-prone. Write a
// program that declares a float array of size 10 and uses a loop to prompt the user to enter the
// marks for each student (out of 20), displaying the prompt as &quot;Enter marks for student 1:&quot; and
// so on. Make the program reject invalid input: if a mark is below 0 or above 20, ask the user
// to re-enter it for that same student before moving on.
// After all marks are stored, use a second loop to display each student&#39;s marks next to a
// remark: &quot;Excellent&quot; for 18 and above, &quot;Good&quot; for 14 to 17.99, &quot;Average&quot; for 10 to 13.99, and
// &quot;Needs Improvement&quot; below 10. Then calculate the class average and use another loop to
// count how many students scored above that average. The instructor realizes that the
// question 4 marking scheme was wrong and every student needs 1.5 bonus marks, capped
// at a maximum of 20. Write a loop that updates every element of the array in place, ensuring
// no value goes above 20, and display the revised report. Your submission should show
// clearly how a single array and loops replaced what would otherwise have required dozens of
// repeated lines of code.
#include<stdio.h>
#define BONUS 1.5

int main() {
    float marks[10];
    int no_of_elemens = sizeof(marks) / sizeof(marks[0]);

    for(int i = 0; i < no_of_elemens; i++) {
    	
        label1:
        printf("\n\nEnter the %d Student marks(out of 20 : ) : ", i+1);
        scanf("%f", &marks[i]);
        if(marks[i] < 0 || marks[i] > 20) {
            goto label1;
        }

        if(marks[i] > 18) {
            printf("EXCELLENT");
        } else if (marks[i] > 14) {
            printf("Good");
        } else if(marks[i] > 10) {
            printf("Average");
        } else {
            printf("Needs Improvement");
        }
    }

    for(int i = 0; i < no_of_elemens; i++) {
        if((marks[i] + BONUS) > 20) {
            printf("\n\nStudent %d marks cannot be bonused", i+1);
        } else {
            marks[i] += 1.5;
        }
        printf("\n\nStudent %d : Mraks %.2f", i+1, marks[i]);
    }
    return 0;
}
