// 0x8036E510 atoi (40b)

extern long strtol(const char*, char**, int);

int atoi(const char* str) {
    return strtol(str, 0, 10);
}
