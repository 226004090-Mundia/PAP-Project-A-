#define ASSET_H

struct Asset {
int id;
char name[50];
char type[30];
float value;
char condition[30];
char department[50];
};

void assetMenu();
void addAsset();
void displayAssets();
