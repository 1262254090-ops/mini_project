#include <stdio.h>

struct MenuItem {
    char name[30];  
    float price;
}; 

int main() {

    // MENU DEFINITION
    struct MenuItem menu[] = {

        {"Burger", 120},
        {"Pizza", 250},
        {"Pasta", 180},
        {"Sandwich", 100},
        {"Cold Drink", 50}
    };

    int menuSize = sizeof(menu) / sizeof(menu[0]);

    int choice[20];
    int quantity[20];
    int count = 0;

    char more;
    float subtotal = 0, gst, total;

    // DISPLAY MENU
    printf("\n========== RESTAURANT MENU ==========\n");
    for (int i = 0; i < menuSize; i++) {
        printf("%d. %-12s Rs %.2f\n", i + 1, menu[i].name, menu[i].price); // Burger       120
                                                                            // Cold Drink   50

    }
    printf("====================================\n");

    // TAKE ORDER
    do {
        printf("\nEnter item number: ");
        scanf("%d", &choice[count]);   //choice = [3,2]
                                        //quantity = [5,4]
        if (choice[count] < 1 || choice[count] > menuSize) {
            printf("invalid item number.");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity[count]);

        count++;

        printf("Do you want to order more items? (y/n): ");
        scanf(" %c", &more);

    } while (more == 'y' || more == 'Y');

    // BILL CALCULATION  
    printf("\n\n=========== BILL ===========\n");
    printf("%-12s %-8s %-6s %-8s\n", "Item", "Price", "Qty", "Total");

    for (int i = 0; i < count;i++) {
        int idx = choice[i] - 1;
        float itemTotal = menu[idx].price * quantity[i];
        subtotal += itemTotal;  //subtotal = subtotal + itemtotal

        printf("%-12s %-8.2f %-6d %-8.2f\n",
               menu[idx].name,
               menu[idx].price,
               quantity[i],
               itemTotal);
    }

    // GST CALCULATION
    gst = subtotal * 0.05;
    total = subtotal + gst;

    // 🎁 FREE ITEM LOGIC
    int freeItemIndex = -1;

    if (total > 500) {
        printf("\n🎉 Congratulations! You are eligible for a FREE item under Rs 100.\n");

        printf("\nEligible Free Items:\n");
        for (int i = 0; i < menuSize; i++) {
            if (menu[i].price <= 100) {
                printf("%d. %s (Rs %.2f)\n", i + 1, menu[i].name, menu[i].price);
            }
        }

        printf("Select free item number: ");
        scanf("%d", &freeItemIndex);

        if (freeItemIndex >= 1 && freeItemIndex <= menuSize &&
            menu[freeItemIndex - 1].price <= 100) {

            printf("Free Item Added: %s\n", menu[freeItemIndex - 1].name);
        } else {
            printf("Invalid free item selection. No free item added.\n");
            freeItemIndex = -1;
        }
    }

    // FINAL BILL DISPLAY
    printf("\n-----------------------------------\n");
    printf("Subtotal:        Rs %.2f\n", subtotal);
    printf("GST (5%%):        Rs %.2f\n", gst);

    if (freeItemIndex != -1) {
        printf("Free Item:       %s (Rs %.2f)\n",
               menu[freeItemIndex - 1].name,
               menu[freeItemIndex - 1].price);
    }

    printf("Total Amount:    Rs %.2f\n", total);
    printf("-----------------------------------\n");
    printf("Thank You! Visit Again 😊\n");

    return 0;
}

