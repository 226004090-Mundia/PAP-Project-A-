#include <stdio.h>
#include <string.h>

void assetMenu(){
    printf("\n==========ASSETS MANAGEMENT==============\n
    printf("1. Add Asset\n");
    printf("2. Display Assets\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

  int choice;
      printf("Choose Asset Type:1.Vechicle 2.Computer 3.Building 4.Funiture\n")

    switch(choice){
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
            printf("Invalid type choice\n");
            return;
    }

    printf("Enter Asset Value N$: ");
    scanf("%f", &assets[assetCount].value);

    if(assets[assetCount].value < 0){
        printf("Value cannot be negative\n");
        return;
    }

    printf("Enter Condition (Good/Bad): ");
    scanf("%s", assets[assetCount].condition);

    printf("Enter Department: ");
    scanf("%s", assets[assetCount].department);

    assetCount++;
    printf("Asset added successfully!\n");
}

void displayAssets(){
    if(assetCount == 0){
        printf("\nNo assets added\n");
        return;
    }

    printf("\n--- All Assets List ---\n");
    for(int i = 0; i < assetCount; i++){
        printf("\nAsset %d:\n", );
        printf(" ID: %d\n",id);
        printf(" Name: %s\n", name);
        printf(" Type: %s\n", type);
        printf(" Value: N$%.2f\n", value);
        printf(" Condition: %s\n",condition);
        printf(" Department: %s\n",department);
    }
}

int main(){
    int choice;

    while {
        DisplayMenu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                assetManagement();
                break;
            case 2:
                displayAssets();
                break;
            case 3:
                printf("Exiting... Thank you\n");
                return 0;
            default:
                printf("Invalid choice! Try 1-3\n");
        }
    }
    return 0;
}
