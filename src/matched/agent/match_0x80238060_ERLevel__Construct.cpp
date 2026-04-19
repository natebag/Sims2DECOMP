/* ERLevel::Construct(ERLevel *) at 0x80238060 (48B) */

struct ERLevel_C {
    char m_pad[189536];
    static void* operator new(unsigned int size, void* ptr);
    ERLevel_C();
    static ERLevel_C* Construct(ERLevel_C* buf);
};

ERLevel_C* ERLevel_C::Construct(ERLevel_C* buf) {
    return new (buf) ERLevel_C();
}
