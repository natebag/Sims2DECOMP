struct AptCIH {
    char pad[0x5C];
    unsigned int m_data;

    int getZombieState() const;
};

int AptCIH::getZombieState() const {
    return (m_data >> 12) & 3;
}
