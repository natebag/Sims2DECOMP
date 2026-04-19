// 0x801A6C3C (152B) CSMTarget::GetVariable(char*) — sibling of ACTTarget.

char* SimsAptMalloc(unsigned int size);
extern "C" int isdigit(int);
extern "C" int strcmp(const char*, const char*);
extern "C" char* strcpy(char*, const char*);

extern char* g_csmLoadedKey;

class CSMTarget {
public:
    char pad_000[0x84];
    int m_field_084;
    char* GetVariable(char* key);
};

char* CSMTarget::GetVariable(char* key) {
    if (isdigit((signed char)*key)) {
        ++key;
    }
    char* buf = SimsAptMalloc(32);
    buf[0] = 0;
    if (strcmp(g_csmLoadedKey, key) == 0) {
        m_field_084 = 1;
        strcpy(buf, "loaded");
    }
    return buf;
}
