struct ERLevel {
    char pad0[0x2C2B8];
    int m_numInstances;

    int IsInstanceListKindaFull(void);
};

int ERLevel::IsInstanceListKindaFull(void) {
    return m_numInstances > 1663;
}
