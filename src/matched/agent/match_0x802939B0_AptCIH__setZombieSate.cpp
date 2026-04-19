// 0x802939B0 (20B) AptCIH::setZombieSate(int)
// Bitfield at IBM bits 18-19 (std bits 12-13) of the 32-bit word at 0x5C.
// Explicit (& 3u) before assignment forces rlwinm(SH=0)+rlwimi(SH=12) — DOL pattern.
// Omitting the & 3u generates rlwimi(SH=12) alone (elides redundant mask).

struct ZombieWord {
    unsigned int m_zombieCount : 16;
    unsigned int pad : 2;
    unsigned int m_zombieState : 2;
    unsigned int pad2 : 12;
};

struct AptCIH {
    char pad[0x5C];
    ZombieWord m_zombie;
    void setZombieSate(int state);
};

void AptCIH::setZombieSate(int state) {
    m_zombie.m_zombieState = (unsigned int)state & 3u;
}
