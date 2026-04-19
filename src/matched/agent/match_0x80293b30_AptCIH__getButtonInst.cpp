// 0x80293b30 (8B) AptCIH::getButtonInst(void) const

struct AptCIH {
    char pad[0x4C];
    void* m_inst;
    void* getButtonInst() const;
};

void* AptCIH::getButtonInst() const {
    return m_inst;
}
