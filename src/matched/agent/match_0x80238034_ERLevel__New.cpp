/* ERLevel::New(void) at 0x80238034 (44B) */

struct ERLevel_N {
    char m_pad[189536];
    static void* operator new(unsigned int size);
    ERLevel_N();
    static ERLevel_N* New();
};

ERLevel_N* ERLevel_N::New() {
    return new ERLevel_N();
}
