// 0x8036EB34 strtok (40b)

extern char g_impure[4];

struct Reent { char pad[0x5C]; char* strtok_last; };

extern char* strtok_r(const char*, const char*, char**);

char* strtok(const char* str, const char* delim) {
    Reent* reent = *(Reent**)g_impure;
    return strtok_r(str, delim, &reent->strtok_last);
}
