struct AptCIH {
    char pad[0x5C];
    unsigned int m_data;

    int getHasClass() const;
};

int AptCIH::getHasClass() const {
    return (m_data >> 14) & 1;
}
