#include <stdio.h>
#include "employee.h"
#include "budget.h"
#include "supplier.h"
#include "asset.h"


int main()
{
    int choice;

    do
    {
        printf("\n--- Municipal Financial Management System ---\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            Displaymenu();
        }
        else if (choice == 2)
        {
            budgetMenu();
        }
        else if (choice == 3)
        {
            supplierMenu();
        }
        else if (choice == 4)
        {
            assetMenu();
        }
        else if (choice == 6)
        {
            printf("Exiting program...\n");
        }
        else
        {
            printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
