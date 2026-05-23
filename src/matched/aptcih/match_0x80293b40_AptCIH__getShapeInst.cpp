// 0x80293b40 (8B) AptCIH::getShapeInst(void) const

struct AptCIH {
    char pad[0x4C];
    void* m_inst;
    void* getShapeInst() const;
};

void* AptCIH::getShapeInst() const {
    return m_inst;
}
