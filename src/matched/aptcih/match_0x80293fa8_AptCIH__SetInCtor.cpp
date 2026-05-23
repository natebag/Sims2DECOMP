// 0x80293fa8 (16B) AptCIH::SetInCtor(unsigned int)
// rlwimi r0, r4, 10, 21, 21 — inserts r4's LSB into IBM bit 21 (m_isInCtor), no pre-mask.
// Unlike setHasClass/setASChanged (int param + cmpwi), the unsigned int param skips bool conversion.

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
    void SetInCtor(unsigned int val);
};

void AptCIH::SetInCtor(unsigned int val) {
    m_zombie.m_isInCtor = val;
}
