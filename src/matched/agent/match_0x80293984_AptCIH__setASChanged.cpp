// 0x80293984 (32B) AptCIH::setASChanged(int)
// rlwimi r0, r9, 15, 16, 16 — inserts bool(val) into IBM bit 16 (m_asChanged).

struct ZombieWord {
    unsigned int m_zombieCount : 16;
    unsigned int m_asChanged : 1;
    unsigned int m_hasClass : 1;
    unsigned int m_zombieState : 2;
    unsigned int pad1 : 1;
    unsigned int m_isInCtor : 1;
    unsigned int pad2 : 10;
};

struct AptCIH {
    char pad[0x5C];
    ZombieWord m_zombie;
    void setASChanged(int val);
};

void AptCIH::setASChanged(int val) {
    m_zombie.m_asChanged = (val != 0);
}
