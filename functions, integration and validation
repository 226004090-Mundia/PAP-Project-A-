#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_BUF 128

/* ---------- Validation helper declarations ---------- */
void   readLine(const char *prompt, char *buf, int size);
void   readNonEmpty(const char *prompt, char *buf, int size);
int    readInt(const char *prompt, int min, int max);
double readDouble(const char *prompt, double min);
void   pauseScreen(void);
void   printLine(char c, int n);
int    equalsIgnoreCase(const char *a, const char *b);
int    containsIgnoreCase(const char *haystack, const char *needle);

/* ---------- Integration: module menus written by teammates ---------- */
void employeeMenu(void);   /* Student 1 */
void budgetMenu(void);     /* Student 2 */
void supplierMenu(void);   /* Student 3 */
void assetMenu(void);      /* Student 4 */
void reportsMenu(void);    /* Student 5 */

/* ---------- Main program functions ---------- */
void displayMenu(void);

/* ============================================================
   MAIN
   ============================================================ */
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

/* ============================================================
   VALIDATION FUNCTIONS
   ============================================================ */
/* Reads one line safely (no buffer overflow) and removes the newline */
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
    } else {                                   /* discard overly long input */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}

/* Removes spaces at the start and end of a string */
static void trim(char *s)
{
    size_t start = 0, len = strlen(s);
    while (s[start] != '\0' && isspace((unsigned char)s[start])) start++;
    if (start > 0) memmove(s, s + start, len - start + 1);
    len = strlen(s);
    while (len > 0 && isspace((unsigned char)s[len - 1])) s[--len] = '\0';
}

/* Keeps asking until the user types something (empty names rejected) */
void readNonEmpty(const char *prompt, char *buf, int size)
{
    for (;;) {
        readLine(prompt, buf, size);
        trim(buf);
        if (strlen(buf) > 0) return;
        printf("  ! Input cannot be empty. Try again.\n");
    }
}

/* Integer between min and max; rejects letters, empty and out-of-range */
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

/* Decimal number not less than min (use 0 to block negatives) */
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

/* Case-insensitive comparison of two strings (uses strlen + tolower) */
int equalsIgnoreCase(const char *a, const char *b)
{
    if (strlen(a) != strlen(b)) return 0;
    for (; *a; a++, b++)
        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) return 0;
    return 1;
}

/* 1 if needle appears anywhere inside haystack, ignoring case */
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

/* ============================================================
   TEMPORARY PLACEHOLDERS - so this file runs on its own.
   When teammates' modules are added, DELETE everything below.
   ============================================================ */
void employeeMenu(void) { printf("\n[Employee module not connected yet]\n"); }
void budgetMenu(void)   { printf("\n[Budget module not connected yet]\n"); }
void supplierMenu(void) { printf("\n[Supplier module not connected yet]\n"); }
void assetMenu(void)    { printf("\n[Asset module not connected yet]\n"); }
void reportsMenu(void)  { printf("\n[Reports module not connected yet]\n"); }
