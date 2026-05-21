// 0x801F0D48 INVTarget::SetCategoryCheatString(char *, int, char *) (112B)

struct CheatStrTemplate11 {
    int a;
    int b;
    short c;
    char d;
} __attribute__((packed));

extern CheatStrTemplate11 g_CategoryTemplate;
extern "C" int strlen(const char*);
extern "C" char* strcat(char*, const char*);

class INVTarget {
public:
    void SetCategoryCheatString(char* dst, int n, char* src);
};

void INVTarget::SetCategoryCheatString(char* dst, int n, char* src) {
    *(CheatStrTemplate11*)dst = g_CategoryTemplate;
    strlen(dst);
    strlen(src);
    strcat(dst, src);
}
