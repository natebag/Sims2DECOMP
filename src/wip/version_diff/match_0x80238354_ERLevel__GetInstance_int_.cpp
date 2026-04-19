// 0x80238354 (20B) ERLevel::GetInstance(int)

typedef void* cObject;

struct ERLevel {
    void* GetInstance(int index);
};

extern char g_erLevelArray[] __attribute__((section(".sdata2")));

cObject ERLevel::GetInstance(int index) {
    int offset = index << 2;
    unsigned int base = (unsigned int)&g_erLevelArray;
    cObject obj = *(cObject*)(base + offset);
    return obj;
}
