#include<stdio.h>
int main(){
    int arr[15];
    int no_of_patients = sizeof(arr) / sizeof(arr[0]);
    int input;
    int patients_waiting = 0;

    int patient_type;
    printf("\n===============================");
    printf("\nHospital Queue Managment System");
    printf("\n===============================");
   
    for(int i = 0; i < no_of_patients; i++) {
        
        printf("\nEnter Token Number for Patient %d : ", i+1);
        scanf("%d", &input);

        if(input == -1) {
            printf("\nRegistration closed");
            break;
        }
        
        do {
            printf("\nPatien Type : ");
            printf("\n1.Emergency");
            printf("\n2. Not emergency");
            printf("\nEnter patient type: ");
            scanf("%d", &patient_type);

            if(patient_type != 1 && patient_type!=2) {
                printf("\nInvalid Patient Category.Enter Again[!]");
            }

        } while(patient_type<=0 || patient_type>2);


         // EMERGENCY: Insert patient at the front
        if(patient_type == 1) {
            for(int j = patients_waiting; j > 0; j--) {
                arr[j] = arr[j-1];
            }
            arr[0] = input;
            patients_waiting++;
        } else {
            arr[patients_waiting] = input;
            patients_waiting++;
        }

        printf("\n\nCurrent Queue:");

        for(int j = 0; j < patients_waiting; j++) {
            printf("\nPosition %d -> Token %d", j+1, arr[j]);
        }

        printf("\nPatients Waiting : %d", patients_waiting);
    }

    char ch;

    while(patients_waiting>0) {
        printf("\n\nPress C to call the next Patient : ");
        scanf(" %c", &ch);

        if(ch != 'C' && ch!= 'c') {
            printf("\nPlease enter C to call a patient.");
            continue;
        }
        
        printf("\nCalling Token Number: %d", arr[0]);

        for (int j = 0; j < patients_waiting - 1; j++) {
            arr[j] = arr[j + 1];
        }
        patients_waiting--;

        printf("\n\nUpdated Queue:");

        if (patients_waiting == 0) {
            printf("\nNo patients are waiting.");
        } else {
            for (int j = 0; j < patients_waiting; j++) {
                printf("\nPosition %d -> Token %d",
                       j + 1, arr[j]);
            }
        }

        printf("\nPatients Waiting count : %d", patients_waiting);
    }
    
    printf("\n\nAll patients have been called.");
    return 0;
}