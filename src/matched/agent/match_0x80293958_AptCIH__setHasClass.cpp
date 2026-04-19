// 0x80293958 (32B) AptCIH::setHasClass(int)
// rlwimi r0, r9, 14, 17, 17 — inserts bool(val) into IBM bit 17 (m_hasClass).

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
    void setHasClass(int val);
};

void AptCIH::setHasClass(int val) {
    m_zombie.m_hasClass = (val != 0);
}
