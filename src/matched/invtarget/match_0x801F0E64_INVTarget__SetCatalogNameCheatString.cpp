// 0x801F0E64 INVTarget::SetCatalogNameCheatString(char *, int, unsigned wchar_t *) (100B)

extern char g_CatalogNameTemplate[];
extern "C" char* strcpy(char*, const char*);
extern "C" int strlen(const char*);
extern void UCS2ToUTF8(unsigned short* src, int len, char* dst);

class INVTarget {
public:
    void SetCatalogNameCheatString(char* dst, int n, unsigned short* src);
};

void INVTarget::SetCatalogNameCheatString(char* dst, int n, unsigned short* src) {
    if (!src) {
        *dst = 0;
        return;
    }
    char* tpl = g_CatalogNameTemplate;
    strcpy(dst, tpl);
    int len = strlen(tpl);
    UCS2ToUTF8(src, -1, dst + len);
}
