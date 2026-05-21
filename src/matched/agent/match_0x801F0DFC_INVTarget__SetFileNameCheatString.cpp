// 0x801F0DFC INVTarget::SetFileNameCheatString(char *, int, char *) (104B)

struct CheatStrTemplate {
    int a;
    int b;
    int c;
};

extern CheatStrTemplate g_FileNameTemplate;
extern "C" int strlen(const char*);
extern "C" char* strcat(char*, const char*);

class INVTarget {
public:
    void SetFileNameCheatString(char* dst, int n, char* src);
};

void INVTarget::SetFileNameCheatString(char* dst, int n, char* src) {
    *(CheatStrTemplate*)dst = g_FileNameTemplate;
    strlen(dst);
    strlen(src);
    strcat(dst, src);
}
