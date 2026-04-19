// 0x801B3DD0 (156B) FCMTarget::GetVariable(char*)
// Inline-literal variant of ACTTarget family — strcmp against "FCM_exists"
// instead of SDA ptr; still 7-byte "loaded" inline strcpy + field @0x84.

char* SimsAptMalloc(unsigned int size);
extern "C" int isdigit(int);
extern "C" int strcmp(const char*, const char*);
extern "C" char* strcpy(char*, const char*);

class FCMTarget {
public:
    char pad_000[0x84];
    int m_field_084;
    char* GetVariable(char* key);
};

char* FCMTarget::GetVariable(char* key) {
    if (isdigit((signed char)*key)) {
        ++key;
    }
    char* buf = SimsAptMalloc(32);
    buf[0] = 0;
    if (strcmp("FCM_exists", key) == 0) {
        m_field_084 = 1;
        strcpy(buf, "loaded");
    }
    return buf;
}
