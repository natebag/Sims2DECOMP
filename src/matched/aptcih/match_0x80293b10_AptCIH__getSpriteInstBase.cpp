// 0x80293b10 (8B) AptCIH::getSpriteInstBase(void) const

struct AptCIH {
    char pad[0x4C];
    void* m_inst;
    void* getSpriteInstBase() const;
};

void* AptCIH::getSpriteInstBase() const {
    return m_inst;
}
