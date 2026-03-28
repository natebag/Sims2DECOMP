extern char *g_fsCommandPrefix;

int strlen(const char *);
int strncmp(const char *, const char *, int);

struct AptActionInterpreter {
    int isFSCommand(char *str);
};

int AptActionInterpreter::isFSCommand(char *str) {
    char *prefix = g_fsCommandPrefix;
    int len = strlen(prefix);
    return strncmp(str, prefix, len) == 0;
}
