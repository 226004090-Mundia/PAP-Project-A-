#include <stdio.h>
#include <string.h>

void Displaymenu()
{

printf("\n");
printf("=============================================");
printf("\nMUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
print("==============================================");

printf("1.Employee Management\n");
printf("2.Budget Management\n");
printf("3.Supplier Management\n");
printf("4.Asset Management\n");
printf("5.Reports\n");
printf("6.Exit\n");
}

float calculateSalary(float BasicSalary, float houseAllowance, float transportAllowance)
{
   return BasicSalary + houseAllowance + transportAllowance;
}

int main(){

char name[40];
int age;
int ID[100];
char departement[100];
float BasicSalary;
float houseAllowance;
float transportAllowance;
float salary;
char Town[30];
char email[50];
char phoneNumber[20];
int choice;

Displaymenu();

     printf("Select choice:");
     scanf("%d", &choice);

     if(choice > 6){
        printf("Invalid choice");
     }else{
        printf("Error");
     }

        switch(choice){

case 1:
     printf("\nEmployee Management:\n");

     printf("Enter Employee name:");
     fgets(name, sizeof(name), stdin);

     printf("Enter age:");
     scanf("%d", &age);

     printf("Enter Employee ID:");
     scanf("%d", &ID);

     printf("Enter phone number:");
     fgets(phoneNumber, sizeof(phoneNumber), stdin);

      printf("Input Departement:");
      fgets(departement, sizeof(departement), stdin);

      printf("Enter email:");
      fgets(email, sizeof(email), stdin);

      printf("Town:");
      fgets(Town, sizeof(Town), stdin);

      printf("Input Basicsalary:");
      scanf("%.2f", &BasicSalary);

      printf("Input housing allowance:");
      scanf("%.2f", &houseAllowance);

      printf("Input transport allowance:");
      scanf("%.2f", &transportAllowance);

     printf("%s", name[40]);
     printf("%d", age);
     printf("%d", ID);
     printf("%s", departement[100]);
     printf("%s", email[50]);
     printf("%s", phoneNumber[20]);
     printf("%s", Town[30]);
     printf("%.2f", salary);
     printf("N$%.2f", houseAllowance);
     printf("N$%.2f", transportAllowance);
     printf("Gross Salary:N$%.2f", salary);

int searchID(int ID, int IDs[100], int size){
         for(int i=0; i< size; i++){
           if(IDs[i]==ID){
         return i; }
}
  return -1;
        }
     printf("Enter ID:");
     scanf("%d", &ID);
     printf("%d", searchID);
   }

}
