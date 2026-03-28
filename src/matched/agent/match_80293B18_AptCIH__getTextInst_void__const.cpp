struct AptCharacterTextInst;

struct AptCIH {
    char pad[0x4C];
    AptCharacterTextInst* m_inst;

    AptCharacterTextInst* getTextInst() const;
};

AptCharacterTextInst* AptCIH::getTextInst() const {
    return m_inst;
}
