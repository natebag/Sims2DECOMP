// 0x80293b20 (8B) AptCIH::getStaticTextInst(void) const

struct AptCIH {
    char pad[0x4C];
    void* m_inst;
    void* getStaticTextInst() const;
};

void* AptCIH::getStaticTextInst() const {
    return m_inst;
}
