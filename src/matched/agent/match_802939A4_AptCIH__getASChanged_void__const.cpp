struct AptCIH {
    char pad[0x5C];
    unsigned int m_data;

    int getASChanged() const;
};

int AptCIH::getASChanged() const {
    return (m_data >> 15) & 1;
}
