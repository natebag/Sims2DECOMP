// MATCH: 0x801E9248 GetVar_EYE_exists::Handler(char *) | Size: 36 bytes
// FLAGS: -O2 -g0

struct EyeExistsData {
    int field0;
    unsigned short field4;
    char field6;
};

extern EyeExistsData g_EYE_exists __attribute__((section(".data")));

struct GetVar_EYE_exists {
    void Handler(char* out);
};

void GetVar_EYE_exists::Handler(char* out) {
    int word = g_EYE_exists.field0;
    out[6] = g_EYE_exists.field6;
    *(unsigned short*)(out + 4) = g_EYE_exists.field4;
    *(int*)out = word;
}
