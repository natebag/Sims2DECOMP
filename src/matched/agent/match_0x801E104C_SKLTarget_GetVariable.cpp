// 0x801E104C (152B) SKLTarget::GetVariable(char*) — sibling of ACTTarget.

char* SimsAptMalloc(unsigned int size);
extern "C" int isdigit(int);
extern "C" int strcmp(const char*, const char*);
extern "C" char* strcpy(char*, const char*);

extern char* g_sklLoadedKey;

class SKLTarget {
public:
    char pad_000[0x84];
    int m_field_084;
    char* GetVariable(char* key);
};

char* SKLTarget::GetVariable(char* key) {
    if (isdigit((signed char)*key)) {
        ++key;
    }
    char* buf = SimsAptMalloc(32);
    buf[0] = 0;
    if (strcmp(g_sklLoadedKey, key) == 0) {
        m_field_084 = 1;
        strcpy(buf, "loaded");
    }
    return buf;
}
