// 0x80293b38 (8B) AptCIH::getAnimationInst(void) const

struct AptCIH {
    char pad[0x4C];
    void* m_inst;
    void* getAnimationInst() const;
};

void* AptCIH::getAnimationInst() const {
    return m_inst;
}
