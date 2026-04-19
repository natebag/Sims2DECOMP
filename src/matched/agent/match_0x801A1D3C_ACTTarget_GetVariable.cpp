// 0x801A1D3C (152B) ACTTarget::GetVariable(char*)
// isdigit prefix skip + SimsAptMalloc(32) + strcmp against SDA ptr +
// on match: set flag at 0xCC and strcpy "loaded".

char* SimsAptMalloc(unsigned int size);
extern "C" int isdigit(int);
extern "C" int strcmp(const char*, const char*);
extern "C" char* strcpy(char*, const char*);

extern char* g_actLoadedKey;  // SDA ptr

class ACTTarget {
public:
    char pad_000[0xCC];
    int m_field_0CC;
    char* GetVariable(char* key);
};

char* ACTTarget::GetVariable(char* key) {
    if (isdigit((signed char)*key)) {
        ++key;
    }
    char* buf = SimsAptMalloc(32);
    buf[0] = 0;
    if (strcmp(g_actLoadedKey, key) == 0) {
        m_field_0CC = 1;
        strcpy(buf, "loaded");
    }
    return buf;
}
