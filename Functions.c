#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_BUF 128


void   readLine(const char *prompt, char *buf, int size);
void   readNonEmpty(const char *prompt, char *buf, int size);
int    readInt(const char *prompt, int min, int max);
double readDouble(const char *prompt, double min);
void   pauseScreen(void);
void   printLine(char c, int n);
int    equalsIgnoreCase(const char *a, const char *b);
int    containsIgnoreCase(const char *haystack, const char *needle);

void employeeMenu(void);   
void budgetMenu(void);     
void supplierMenu(void);   
void assetMenu(void);      
void reportsMenu(void);    


void displayMenu(void);



int main(void)
{
    int running = 1;
    while (running) {
        displayMenu();
        switch (readInt("Enter your choice: ", 1, 6)) {
            case 1: employeeMenu(); break;
            case 2: budgetMenu();   break;
            case 3: supplierMenu(); break;
            case 4: assetMenu();    break;
            case 5: reportsMenu();  break;
            case 6: running = 0;    break;
        }
    }
    printf("Goodbye!\n");
    return 0;
}

void displayMenu(void)
{
    printLine('=', 40);
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printLine('=', 40);
    printf("1. Employee Management\n"
           "2. Budget Management\n"
           "3. Supplier Management\n"
           "4. Asset Management\n"
           "5. Reports\n"
           "6. Exit\n");
}


void readLine(const char *prompt, char *buf, int size)
{
    printf("%s", prompt);
    if (fgets(buf, size, stdin) == NULL) {
        printf("\nInput closed. Exiting.\n");
        exit(0);
    }
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    } else {                                  
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}


static void trim(char *s)
{
    size_t start = 0, len = strlen(s);
    while (s[start] != '\0' && isspace((unsigned char)s[start])) start++;
    if (start > 0) memmove(s, s + start, len - start + 1);
    len = strlen(s);
    while (len > 0 && isspace((unsigned char)s[len - 1])) s[--len] = '\0';
}


void readNonEmpty(const char *prompt, char *buf, int size)
{
    for (;;) {
        readLine(prompt, buf, size);
        trim(buf);
        if (strlen(buf) > 0) return;
        printf("  ! Input cannot be empty. Try again.\n");
    }
}


int readInt(const char *prompt, int min, int max)
{
    char line[LINE_BUF], *end;
    for (;;) {
        readLine(prompt, line, sizeof line);
        trim(line);
        if (strlen(line) == 0) { printf("  ! Please enter a number.\n"); continue; }
        long v = strtol(line, &end, 10);
        if (*end != '\0')       { printf("  ! Invalid number.\n"); continue; }
        if (v < min || v > max) { printf("  ! Value must be between %d and %d.\n", min, max); continue; }
        return (int)v;
    }
}


double readDouble(const char *prompt, double min)
{
    char line[LINE_BUF], *end;
    for (;;) {
        readLine(prompt, line, sizeof line);
        trim(line);
        if (strlen(line) == 0) { printf("  ! Please enter an amount.\n"); continue; }
        double v = strtod(line, &end);
        if (*end != '\0') { printf("  ! Invalid number.\n"); continue; }
        if (v < min)      { printf("  ! Value cannot be less than %.2f.\n", min); continue; }
        return v;
    }
}

void pauseScreen(void)
{
    char tmp[LINE_BUF];
    readLine("\nPress ENTER to continue...", tmp, sizeof tmp);
}

void printLine(char c, int n)
{
    for (int i = 0; i < n; i++) putchar(c);
    putchar('\n');
}


int equalsIgnoreCase(const char *a, const char *b)
{
    if (strlen(a) != strlen(b)) return 0;
    for (; *a; a++, b++)
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) return 0;
    return 1;
}


int containsIgnoreCase(const char *haystack, const char *needle)
{
    size_t hl = strlen(haystack), nl = strlen(needle);
    if (nl == 0) return 1;
    if (nl > hl) return 0;
    for (size_t i = 0; i + nl <= hl; i++) {
        size_t j = 0;
        while (j < nl && tolower((unsigned char)haystack[i + j]) == tolower((unsigned char)needle[j])) j++;
        if (j == nl) return 1;
    }
    return 0;
}


void employeeMenu(void) { printf("\n[Employee module not connected yet]\n"); }
void budgetMenu(void)   { printf("\n[Budget module not connected yet]\n"); }
void supplierMenu(void) { printf("\n[Supplier module not connected yet]\n"); }
void assetMenu(void)    { printf("\n[Asset module not connected yet]\n"); }
void reportsMenu(void)  { printf("\n[Reports module not connected yet]\n"); }
