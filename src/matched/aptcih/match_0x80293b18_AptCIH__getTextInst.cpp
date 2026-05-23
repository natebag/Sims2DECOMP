// 0x80293b18 (8B) AptCIH::getTextInst(void) const

struct AptCIH {
    char pad[0x4C];
    void* m_inst;
    void* getTextInst() const;
};

void* AptCIH::getTextInst() const {
    return m_inst;
}
