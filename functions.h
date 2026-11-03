#ifndef DATATYPES_H
#define DATATYPES_H
struct MainData {
    int running;
};
struct ValidationData {
    int min;
    int max;
    int size;
    double minValue;
};
struct StringData {
    char line[128];
    char tmp[128];
    char *end;
    const char *prompt;
    const char *haystack;
    const char *needle;
};
struct FormattingData {
    char c;
    int n;
};
struct LengthData {
    size_t len;
    size_t hl;
    size_t nl;
    size_t start;
    size_t i;
    size_t j;
};

#endif
