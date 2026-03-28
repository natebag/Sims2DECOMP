struct AptCIH {
    char pad[0x5C];
    unsigned short m_zombieCount;

    void incZombieCount();
};

void AptCIH::incZombieCount() {
    m_zombieCount++;
}
