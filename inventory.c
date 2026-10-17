#include<stdio.h>
int main() {
    int stockRemaining[] = {25, 12, 8, 40, 5, 18, 3, 22};
    int no_of_elements = sizeof(stockRemaining)/sizeof(stockRemaining[0]);
    for(int i = 0; i < no_of_elements; i++) {
        if(stockRemaining[i]<10) {
            printf("\nItem %d is LOW on Stock - Reoreder Required", i+1);
        } else {
            printf("\nItem %d Stock Remaining : %d", i+1, stockRemaining[i]);
        }
    }

    int itemNo;
    int quantitySold;

    do {
        do {
            printf("\nEnter The item No : ");
            scanf("%d", &itemNo);
        } while(itemNo<0 || itemNo>no_of_elements);

        if(itemNo==0) {
            printf("\nLuch Rush has Ended");
            break;
        }

        do {
            printf("\nEnter the Quantity Sold : ");
            scanf("%d", &quantitySold);

            if(quantitySold<0 || quantitySold>stockRemaining[itemNo-1]) {
                printf("\nInvalid Input[!].Enter Correct Quantity Sold");
            }
        } while(quantitySold<0 || quantitySold>stockRemaining[itemNo-1]);

        stockRemaining[itemNo-1] -= quantitySold;
        printf("\nremaining quantity has updated successfully");

    } while(itemNo != 0);


    int total_rem_qty = 0;
    int min_qty_pos = 0;
    int min_stock_qty = stockRemaining[0];

    printf("\n\n--- Final Stock Levels ---");

    for(int i = 0; i < no_of_elements; i++) {
        if(stockRemaining[i] < 10) {
            printf("\nItem %d is LOW on Stock - Reoreder Required", i+1);
        } else {
            printf("\nItem %d Stock Remaining %d", i+1, stockRemaining[i]);
        }
        total_rem_qty += stockRemaining[i];

        if(min_stock_qty > stockRemaining[i]) {
            min_stock_qty = stockRemaining[i];
            min_qty_pos = i;
        }
    }

    printf("\nitem with least Quantity: Item %d", min_qty_pos + 1);
    printf("\nLeast Stock Quantity: %d", min_stock_qty);
    printf("\nTotal Remaining Quantity in Stock : %d", total_rem_qty);
    return 0;
}