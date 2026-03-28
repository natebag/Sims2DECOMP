struct AptCharacterMorphInst;

struct AptCIH {
    char pad[0x4C];
    AptCharacterMorphInst* m_inst;

    AptCharacterMorphInst* getMorphInst() const;
};

AptCharacterMorphInst* AptCIH::getMorphInst() const {
    return m_inst;
}
