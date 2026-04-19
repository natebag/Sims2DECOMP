/* 0x802939B0 (64B) AptCIH::setZombieState(int) */

struct AptCIH_setZombieState {
    char pad[0x5C];
    struct {
        unsigned int _hi : 12;
        unsigned int zombieState : 2;
        unsigned int hasClass : 1;
        unsigned int asChanged : 1;
        unsigned int _lo : 16;
    } m_flags;

    void setZombieState(int v);
};

void AptCIH_setZombieState::setZombieState(int v) {
    int b = v ? 1 : 0;
    unsigned int f = m_flags;
    f = (f & ~0x00006000) | (b << 12);
    m_flags = f;
}
