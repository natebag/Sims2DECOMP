// 0x801DA538 (156B) PRGTarget::GetVariable(char*) — sibling of FCMTarget.

char* SimsAptMalloc(unsigned int size);
extern "C" int isdigit(int);
extern "C" int strcmp(const char*, const char*);
extern "C" char* strcpy(char*, const char*);

class PRGTarget {
public:
    char pad_000[0x84];
    int m_field_084;
    char* GetVariable(char* key);
};

char* PRGTarget::GetVariable(char* key) {
    if (isdigit((signed char)*key)) {
        ++key;
    }
    char* buf = SimsAptMalloc(32);
    buf[0] = 0;
    if (strcmp("PRG_exists", key) == 0) {
        m_field_084 = 1;
        strcpy(buf, "loaded");
    }
    return buf;
}
