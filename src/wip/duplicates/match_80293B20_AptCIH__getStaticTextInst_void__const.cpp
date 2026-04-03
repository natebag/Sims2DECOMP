struct AptCharacterStaticTextInst;

struct AptCIH {
    char pad[0x4C];
    AptCharacterStaticTextInst* m_inst;

    AptCharacterStaticTextInst* getStaticTextInst() const;
};

AptCharacterStaticTextInst* AptCIH::getStaticTextInst() const {
    return m_inst;
}
