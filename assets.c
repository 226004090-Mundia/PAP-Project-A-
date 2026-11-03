#include <stdio.h>
#include <string.h>
#include "assets.h"

struct Asset assets[100];
int assetCount = 0;

void assetMenu(){
    int choice;
    
    do {
        printf("\n== ASSETS MANAGEMENT ==\n");
        printf("1. Add Asset\n");
        printf("2. Display Assets\n");
        prinft("3. Search Assets\n"); 
        printf("4. Assets Report\n");
        printf("5. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Asset ID: ");
            scanf("%d", &assets[assetCount].id);

            printf("Enter Asset Name: ");
            scanf(" %[^\n]", assets[assetCount].name);

            if(strlen(assets[assetsCount].name) == 0){
                printf("name cannot be empty!\n");
            }   
            
            printf("Choose Asset Type (1. Vehicle, 2. Computer, 3. Building, 4. Furniture): ");
            int typeChoice;
            scanf("%d", &typeChoice);

            switch(typeChoice){
                case 1:
                    strcpy(assets[assetCount].type, "Vehicle");
                    break;
                case 2:
                    strcpy(assets[assetCount].type, "Computer");
                    break;
                case 3:
                    strcpy(assets[assetCount].type, "Building");
                    break;
                case 4:
                    strcpy(assets[assetCount].type, "Furniture");
                    break;
                default:
                    strcpy(assets[assetCount].type, "Other");
                    break;
            }

            printf("Enter Asset Value N$: ");
            scanf("%lf", &assets[assetCount].value);

            if(assets[assetCount].value < 0){
                printf("Value cannot be negative!\n");
                continue;
            }

            printf("Enter Condition (Good/Bad): ");
            scanf("%s", assets[assetCount].condition);

            printf("Enter Department: ");
            scanf("%s", assets[assetCount].department);

            assetCount++;
            printf("Asset added successfully!\n");
        }
        else if (choice == 2) {
            displayAssets();
        }
        else if (choice == 3) {
            searchAssets();
        } 
        else if (choice == 4){
            assetsReport();
        }
        else if (choice == 5){
            printf("Returning to main menu...\n");
        }
        else {
            printf("Invalid choice! Try 1-5\n");
        }

    } while (choice != 5);
}

void displayAssets(){
    if(assetCount == 0){
        printf("\nNo assets added yet.\n");
        return;
    }

    printf("\n--- All Assets List ---\n");
    for(int i = 0; i < assetCount; i++){
        printf("\nAsset %d:\n", i + 1);
        printf(" ID: %d\n", assets[i].id);
        printf(" Name: %s\n", assets[i].name);
        printf(" Type: %s\n", assets[i].type);
        printf(" Value: N$%.2f\n", assets[i].value);
        printf(" Condition: %s\n", assets[i].condition);
        printf(" Department: %s\n", assets[i].department);
    }
}
 void searchAssets(){
     char key [50];
     printf('Enter Assets name to search : ");
    scanf(" %s", key);

   if(strlen(key) ==0){
       printf("Search cannot be empty!\n");
       return;
   }
   int found =0; 
   for (int i = 0; i< assetsCount; i++){
        if (strcmp(assets[i].name, key) == 0){
            printf("\nfound Assets : \n");
            printf(" ID: %d\n", assets[i].id);
            printf(" Name: %s\n, assets[i].name);
            printf("Type: %s\n", assets[i]. type);
            printf("Value: N$%.2lf\n". assets[i].value);
            printf("Condition: %s\n", assets[i].condition);
            printf(" Department: %s\n",assets[i].department);
           found = 1;     
        }
   }
    if (found == 0){
        printf("Assets %s not found!\n", key);
    }
 }
 void assetsReport(){
     if(assetsCount == 0){
        printf("\nNo assets to report.\n");
        return;
     }
     double total =0;
     for(int i = 0; i < assetCount; i++){
         total += assets[i].value;
     }
     printf("\n==== ASSETS REPORT ====\n");
     printf("Total Assets: %d\n", assetsCount);
     printf("Total Value: N$%.2lf\n", total);
 }

