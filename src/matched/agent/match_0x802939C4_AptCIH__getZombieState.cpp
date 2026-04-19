// 0x802939C4 (12B) AptCIH::getZombieState(void)
// lwz+rlwinm(SH=20,MB=30,ME=31): reads 32-bit word at 0x5C, extracts IBM bits 18-19 (std bits 12-13).

struct AptCIH {
    char pad[0x5C];
    unsigned short m_zombieCount;
    int getZombieState() const;
};

int AptCIH::getZombieState() const {
    return (*(const unsigned int*)&m_zombieCount >> 12) & 3;
}
