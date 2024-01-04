#include <stdio.h>
#include <stdlib.h>

// Define the structure for each item in the inventory
struct InventoryItem {
    int itemCode;
    char itemName[50];
    int quantity;
    float price;
};

// Function prototypes
void addStock(struct InventoryItem inventory[], int *itemCount);
void deleteStock(struct InventoryItem inventory[], int *itemCount);
void displayStock(struct InventoryItem inventory[], int itemCount);
float calculateTotalAmount(struct InventoryItem inventory[], int itemCount);

int main() {
    // Maximum number of items in the inventory
    const int MAX_ITEMS = 100;

    // Array to store inventory items
    struct InventoryItem inventory[MAX_ITEMS];

    // Variable to keep track of the number of items in the inventory
    int itemCount = 0;

    int choice;

    do {
        // Display menu
        printf("\n===== Inventory Management System =====\n");
        printf("1. Add Stock\n");
        printf("2. Delete Stock\n");
        printf("3. Display Stock\n");
        printf("4. Calculate Total Amount\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStock(inventory, &itemCount);
                break;
            case 2:
                deleteStock(inventory, &itemCount);
                break;
            case 3:
                displayStock(inventory, itemCount);
                break;
            case 4:
                printf("Total Amount: $%.2f\n", calculateTotalAmount(inventory, itemCount));
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add stock to the inventory
void addStock(struct InventoryItem inventory[], int *itemCount) {
    if (*itemCount < 100) { // Assuming a maximum of 100 items in the inventory
        printf("Enter details for the new item:\n");
        printf("Item Code: ");
        scanf("%d", &inventory[*itemCount].itemCode);
        printf("Item Name: ");
        scanf("%s", inventory[*itemCount].itemName);
        printf("Quantity: ");
        scanf("%d", &inventory[*itemCount].quantity);
        printf("Price: $");
        scanf("%f", &inventory[*itemCount].price);

        (*itemCount)++;
        printf("Stock added successfully!\n");
    } else {
        printf("Inventory is full. Cannot add more stock.\n");
    }
}

// Function to delete stock from the inventory
void deleteStock(struct InventoryItem inventory[], int *itemCount) {
    int codeToDelete;
    printf("Enter the item code to delete: ");
    scanf("%d", &codeToDelete);

    int found = 0;
    for (int i = 0; i < *itemCount; i++) {
        if (inventory[i].itemCode == codeToDelete) {
            // Shift items to fill the gap
            for (int j = i; j < *itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*itemCount)--;
            found = 1;
            printf("Stock deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Item not found in the inventory.\n");
    }
}

// Function to display the current stock in the inventory
void displayStock(struct InventoryItem inventory[], int itemCount) {
    if (itemCount > 0) {
        printf("\n===== Current Inventory Stock =====\n");
        printf("Item Code\tItem Name\tQuantity\tPrice\n");
        for (int i = 0; i < itemCount; i++) {
            printf("%d\t\t%s\t\t%d\t\t$%.2f\n",
                   inventory[i].itemCode, inventory[i].itemName,
                   inventory[i].quantity, inventory[i].price);
        }
    } else {
        printf("Inventory is empty.\n");
    }
}

// Function to calculate the total amount of the inventory
float calculateTotalAmount(struct InventoryItem inventory[], int itemCount) {
    float totalAmount = 0;
    for (int i = 0; i < itemCount; i++) {
        totalAmount += inventory[i].quantity * inventory[i].price;
    }
    return totalAmount;
}
