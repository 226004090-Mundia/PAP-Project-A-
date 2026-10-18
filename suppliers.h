#define MAX_SUPPLIERS 100

struct supplier
{
    char supplierID[20];
    char supplierName[100];
    char email[100];
    char telephone[20];
    char town[50];
};

void supplierMenu();
void addSupplier();
void displaySuppliers();
void searchSupplier();
