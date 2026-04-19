// 0x80197C84 (120B) CASGeneticsTarget::GetVariable(char*)
// Inline-literal variant without isdigit prefix and without field-@0x84 set —
// simplest form: strcmp("CGE_exists", key) == 0 → strcpy(buf, "loaded").

char* SimsAptMalloc(unsigned int size);
extern "C" int strcmp(const char*, const char*);
extern "C" char* strcpy(char*, const char*);

class CASGeneticsTarget {
public:
    char* GetVariable(char* key);
};

char* CASGeneticsTarget::GetVariable(char* key) {
    char* buf = SimsAptMalloc(32);
    buf[0] = 0;
    if (strcmp("CGE_exists", key) == 0) {
        strcpy(buf, "loaded");
    }
    return buf;
}
