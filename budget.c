
#include <stdio.h>
#include <string.h>

char budgetDept[20][30];
double budgetAllocated[20];
double budgetSpent[20];
int deptCount = 0;

int budgetGetChoice(char message[], int min,int max)
{
    int choice;
    char junk[50];
    int valid;

 do{
        valid= 1;
        printf("%s", message);
        if (scanf("%d", &choice) != 1)
        {
            scanf("%49s", junk);
            valid = 0;
        } else if (choice< min || choice > max){
            valid = 0;
        }
        if(valid == 0) {
            printf("Invalid input, Enter number from %d to %d\n", min, max);
        }
        } while (valid == 0);
        return choice;
            }
        double budgetGetAmount(char message[], double min)
{
    double amount;
    char junk[50];
    int valid;
    do {
        valid = 1;
        printf("%s", message);
            if
                (scanf("%lf", &amount) !=1)
            {
                scanf("%49s", junk);
                valid= 0;
            } else if (amount< min) {
                valid = 0;
            }
        if (valid== 0) {
                printf("Invalid amount, Enter a number atleast %.0f\n", min);
        }
            } while(valid == 0);
            
            return amount;
        }

        double calculateRemaining(double allocated, double spent)
        {
            return allocated - spent;
        }

        void displayDepartment(int i)
        {
            double remaining;
            
            remaining = calculateRemaining(budgetAllocated[i], budgetSpent[i]);

            printf("Department: %s\n", budgetDept[i]);
            printf("Allocated Budget: N$%.2f\n", budgetAllocated[i]);
            printf("Expenditure: N$%.2f\n", budgetSpent[i]);
            printf("Remaining Budget: N$%.2f\n", remaining);
            if (budgetSpent[i] > budgetAllocated[i]) {
                printf("Status: Over Budget\n");
            } else {
                printf("Status: Within Budget\n");
            }
        }
            void addDepartmentBudget () 
            {
                char name[30];
                int i;
                int exists = 0;

                printf("--- ADD DEPARTMENT BUDGET ---\n");
                if (deptCount >= 20){
                    printf("Departement list is full.\n");
                } else {
                    printf("Enter department name:\n");
                    scanf(" %29[^\n]", name);

                    for (i= 0; i < deptCount; i++) {
                        if(
                            strcmp(budgetDept[i], name) == 0
                        ) {
                            exists = 1;
                        }
                    }
                    if (exists== 1) {
                        printf("That department already exists\n");
                    } else { 
                        strcpy(budgetDept[deptCount], name);
                        budgetAllocated[deptCount] = budgetGetAmount("Enter allocated budget (N$): ", 0);
                            budgetSpent[deptCount]= 0;
                        deptCount++;
                        printf("Department budget added\n");
                           } 
                }
                }
        void recordExpenditure () 
        {
            int i;
            int choice;
            double amount;

            printf("\n--- Record Expenditure---\n");
            if (deptCount == 0){
                printf("No departments entered yet, Enter a department budget.\n");
            } else {
                    for(i = 0; i< deptCount; i++) {
                       printf("%d. %s\n", i +1, budgetDept[i]);
                    }   
            choice = budgetGetChoice("Select department number: ", 1, deptCount) - 1;
            amount = budgetGetAmount("Enter expediture amount(N$): ", 0);
                budgetSpent[choice] = budgetSpent[choice] +amount;
            displayDepartment(choice);
            if(budgetSpent[choice]> budgetAllocated[choice]) {
                printf("%s IS NOT WITHIN THE ALLOCATED BUDGET!!\n", budgetDept[choice]);    
            }
            }
        }
        void displayExceededDepartment () 
        {
            int i;
            int found= 0 ;

            for (i= 0; i< deptCount; i++) {
                if(budgetSpent[i] > budgetAllocated[i]) {
                    printf("%s is over budget by N$%.2f\n", budgetDept[i], budgetSpent[i] - budgetAllocated[i]);
                    found++;
                }
            }
            if(found == 0){
                printf("All departments are within budget\n");
            }
        }

            void displayBudget()
            {
                int i;
                printf("\n---BUDGET INFORMATION---\n");
                if (deptCount == 0)
                {
                printf("No departments entered yet\n");
            } else {
                    for (i = 0; i< deptCount; i++)
                        {
                            displayDepartment(i);
                        }
            }
         }     
            
        void budgetMenu ()
        {
            int choice;

            do {
                printf("\n======== BUDGET MANAGEMENT========\n");
                printf("1.Enter department budget\n");
                printf("2.Enter expenditure\n");
                printf("3.Display budget information\n");
                printf("4.Display over budget\n");
                printf("5.Main menu\n");
                choice = budgetGetChoice("Enter your choice:", 1, 5);
                switch(choice) {
                    case 1: 
                        addDepartmentBudget();
                    break;
                    case 2: 
                        recordExpenditure();
                    break;
                    case 3: 
                        displayBudget();
                    break;
                    case 4:
                        printf("\n---Department over budget---\n");
                    displayExceededDepartment();
                    break;
                    
                    case 5:
                    printf("Return to main menu\n");
                    break;
                    default:
                    printf("Invalid choice.Try again\n");
                }
            } while(choice != 5);
                }
