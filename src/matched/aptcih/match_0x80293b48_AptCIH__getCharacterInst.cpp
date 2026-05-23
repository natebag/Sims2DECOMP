// 0x80293b48 (8B) AptCIH::getCharacterInst(void) const

struct AptCIH {
    char pad[0x4C];
    void* m_inst;
    void* getCharacterInst() const;
};

void* AptCIH::getCharacterInst() const {
    return m_inst;
}
