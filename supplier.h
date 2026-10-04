#define MAX_SUPPLIERS 100

typedef struct
{
    char supplierID[20];
    char supplierName[100];
    char email[100];
    char telephone[20];
    char town[50];
} Supplier;

void supplierMenu();
void addSupplier();
void displaySuppliers();
void searchSupplier();