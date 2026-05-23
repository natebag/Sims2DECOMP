// 0x80293b28 (8B) AptCIH::getMorphInst(void) const

struct AptCIH {
    char pad[0x4C];
    void* m_inst;
    void* getMorphInst() const;
};

void* AptCIH::getMorphInst() const {
    return m_inst;
}
