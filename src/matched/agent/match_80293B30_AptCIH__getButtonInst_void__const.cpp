struct AptCharacterButtonInst;

struct AptCIH {
    char pad[0x4C];
    AptCharacterButtonInst* m_inst;

    AptCharacterButtonInst* getButtonInst() const;
};

AptCharacterButtonInst* AptCIH::getButtonInst() const {
    return m_inst;
}
