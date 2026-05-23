// 0x802939D0 (16B) AptCIH::incZombieCount(void)

struct AptCIH {
    char pad[0x5C];
    unsigned short m_zombieCount;
    void incZombieCount();
};

void AptCIH::incZombieCount() {
    ++m_zombieCount;
}
