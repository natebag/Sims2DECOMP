/* 0x80238034 (44 bytes) - ERLevel::New(void) */
struct ERLevel {
    char m_pad[189536];
    static void* operator new(unsigned int size);
    ERLevel();
    static ERLevel* New();
};

ERLevel* ERLevel::New() {
    return new ERLevel();
}
