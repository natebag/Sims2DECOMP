/* 0x80238060 (48 bytes) - ERLevel::Construct(ERLevel*) */
struct ERLevel {
    char m_pad[189536];
    static void* operator new(unsigned int size, void* ptr);
    ERLevel();
    static ERLevel* Construct(ERLevel* buf);
};

ERLevel* ERLevel::Construct(ERLevel* buf) {
    return new (buf) ERLevel();
}
