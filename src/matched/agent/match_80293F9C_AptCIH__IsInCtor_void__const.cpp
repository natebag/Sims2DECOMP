struct AptCIH {
    char pad[0x5C];
    unsigned int m_data;

    int IsInCtor() const;
};

int AptCIH::IsInCtor() const {
    return (m_data >> 10) & 1;
}
