#include <stdio.h>
#include <string.h>
#include "supplier.h"

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

void supplierMenu()
{
    int choice;

    do
    {
        printf("\n--- Supplier Management ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addSupplier();
        }
        else if (choice == 2)
        {
            displaySuppliers();
        }
        else if (choice == 3)
        {
            searchSupplier();
        }
        else if (choice == 4)
        {
            printf("\nReturning to main menu...\n");
        }
        else
        {
            printf("\nInvalid choice.\n");
        }

    } while (choice != 4);
}

void addSupplier()
{
    if (supplierCount >= MAX_SUPPLIERS)
{
    printf("Supplier list is full.\n");
    return;
}
    printf("\nAdd Supplier\n");

    printf("Enter Supplier ID: ");
    scanf("%s", suppliers[supplierCount].supplierID);

    printf("Enter Supplier Name: ");
    scanf(" %[^\n]", suppliers[supplierCount].supplierName);

    printf("Enter Email: ");
    scanf("%s", suppliers[supplierCount].email);

    printf("Enter Telephone: ");
    scanf("%s", suppliers[supplierCount].telephone);

    printf("Enter Town/Location: ");
    scanf(" %[^\n]", suppliers[supplierCount].town);

    supplierCount++;

    printf("\nSupplier added successfully!\n");
}

void displaySuppliers()
{
    int i;

    printf("\n Supplier List \n");

    if (supplierCount == 0)
    {
        printf("No suppliers found.\n");
    }
    else
    {
        for (i = 0; i < supplierCount; i++)
        {
            printf("\nSupplier %d\n", i + 1);
            printf("Supplier ID: %s\n", suppliers[i].supplierID);
            printf("Supplier Name: %s\n", suppliers[i].supplierName);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].telephone);
            printf("Town/Location: %s\n", suppliers[i].town);
        }
    }
}

void searchSupplier()
{
    char searchID[20];
    int i;
    int found = 0;

    printf("\nSearch Supplier\n");

    printf("Enter Supplier ID: ");
    scanf("%s", searchID);

    for (i = 0; i < supplierCount; i++)
    {
        if (strcmp(suppliers[i].supplierID, searchID) == 0)
        {
            printf("\nSupplier Found!\n");
            printf("Supplier ID: %s\n", suppliers[i].supplierID);
            printf("Supplier Name: %s\n", suppliers[i].supplierName);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].telephone);
            printf("Town/Location: %s\n", suppliers[i].town);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nSupplier not found.\n");
    }
}