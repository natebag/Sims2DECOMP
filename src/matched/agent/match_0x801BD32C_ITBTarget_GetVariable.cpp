// 0x801BD32C (156B) ITBTarget::GetVariable(char*) — sibling of FCMTarget.

char* SimsAptMalloc(unsigned int size);
extern "C" int isdigit(int);
extern "C" int strcmp(const char*, const char*);
extern "C" char* strcpy(char*, const char*);

class ITBTarget {
public:
    char pad_000[0x84];
    int m_field_084;
    char* GetVariable(char* key);
};

char* ITBTarget::GetVariable(char* key) {
    if (isdigit((signed char)*key)) {
        ++key;
    }
    char* buf = SimsAptMalloc(32);
    buf[0] = 0;
    if (strcmp("ITB_exists", key) == 0) {
        m_field_084 = 1;
        strcpy(buf, "loaded");
    }
    return buf;
}
