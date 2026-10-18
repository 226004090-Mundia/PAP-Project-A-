#include <stdio.h>
#include <string.h>
#include "employees.h"

struct Employee employees[100];
int employeeCount = 0;

void Displaymenu()
{
    int choice;
    
    do {
        printf("\n==============================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM - EMPLOYEES\n");
        printf("==============================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Back to Main Menu\n");
        printf("Select choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (employeeCount >= 100) {
                printf("Employee limit reached!\n");
                continue;
            }

            printf("Enter Employee ID: ");
            scanf("%d", &employees[employeeCount].ID);

            printf("Enter Employee Name: ");
            scanf(" %[^\n]", employees[employeeCount].name);

            printf("Enter Department: ");
            scanf(" %[^\n]", employees[employeeCount].departement);

            printf("Enter Email: ");
            scanf("%s", employees[employeeCount].email);

            printf("Enter Phone Number: ");
            scanf("%s", employees[employeeCount].phoneNumber);

            printf("Enter Town: ");
            scanf(" %[^\n]", employees[employeeCount].Town);

            printf("Enter Basic Salary: ");
            scanf("%f", &employees[employeeCount].BasicSalary);

            printf("Enter Housing Allowance: ");
            scanf("%f", &employees[employeeCount].houseAllowance);

            printf("Enter Transport Allowance: ");
            scanf("%f", &employees[employeeCount].transportAllowance);

            employeeCount++;
            printf("Employee added successfully!\n");
        }
        else if (choice == 2) {
            if (employeeCount == 0) {
                printf("\nNo employees recorded yet.\n");
            } else {
                printf("\n--- EMPLOYEE LIST ---\n");
                for (int i = 0; i < employeeCount; i++) {
                    float gross = employees[i].BasicSalary + employees[i].houseAllowance + employees[i].transportAllowance;
                    printf("\nEmployee %d:\n", i + 1);
                    printf(" ID: %d\n", employees[i].ID);
                    printf(" Name: %s\n", employees[i].name);
                    printf(" Department: %s\n", employees[i].departement);
                    printf(" Gross Salary: N$%.2f\n", gross);
                }
            }
        }
        else if (choice == 3) {
            printf("Returning to main menu...\n");
        }
        else {
            printf("Invalid choice. Please choose between 1 and 3.\n");
        }

    } while (choice != 3);
}

float calculateSalary(float BasicSalary, float houseAllowance, float transportAllowance)
{
   return BasicSalary + houseAllowance + transportAllowance;
}
