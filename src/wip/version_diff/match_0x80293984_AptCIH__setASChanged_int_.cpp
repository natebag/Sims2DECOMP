/* 0x80293984 (64B) AptCIH::setASChanged(int) */

struct AptCIH_setASChanged {
    char pad[0x5C];
    struct {
        unsigned int _hi : 15;
        unsigned int asChanged : 1;
        unsigned int hasClass : 1;
        unsigned int zombieState : 2;
        unsigned int _lo : 13;
    } m_flags;

    void setASChanged(int v);
};

void AptCIH_setASChanged::setASChanged(int v) {
    int b = v ? 1 : 0;
    unsigned int f = m_flags;
    f = (f & ~0x00008000) | (b << 15);
    m_flags = f;
}
