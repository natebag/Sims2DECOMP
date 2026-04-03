struct AptCharacterInst;

struct AptCIH {
    char pad[0x4C];
    AptCharacterInst* m_inst;

    AptCharacterInst* getCharacterInst() const;
};

AptCharacterInst* AptCIH::getCharacterInst() const {
    return m_inst;
}
