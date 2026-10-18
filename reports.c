#include <stdio.h>
#include "reports.h"

void displayReportsMenu() {
    int choice;

    do {
        printf("\nMUNICIPAL FINANCIAL MANAGEMENT SYSTEM - REPORTS\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("[Error] Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("\nEMPLOYEE REPORT\n");
                printf("Note: Managed via Employee module structures.\n");
                break;
            case 2:
                printf("\nBUDGET REPORT\n");
                displayDepartment();
                displayExceededDepartment();
                break;
            case 3:
                printf("\nSUPPLIER REPORT\n");
                displaySuppliers();
                break;
            case 4:
                printf("\nASSET REPORT\n");
                displayAssets();
                break;
            case 5:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("[Error] Invalid option. Choose between 1 and 5.\n");
        }
    } while (choice != 5);
}