// 0x80293b08 (8B) AptCIH::getSpriteInst(void) const

struct AptCIH {
    char pad[0x4C];
    void* m_inst;
    void* getSpriteInst() const;
};

void* AptCIH::getSpriteInst() const {
    return m_inst;
}
