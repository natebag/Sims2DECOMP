struct AptCIH {
    char pad[0x5C];
    unsigned short m_zombieCount;

    unsigned short getZombieCount();
};

unsigned short AptCIH::getZombieCount() {
    return m_zombieCount;
}
