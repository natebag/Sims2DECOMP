struct AptCharacterShapeInst;

struct AptCIH {
    char pad[0x4C];
    AptCharacterShapeInst* m_inst;

    AptCharacterShapeInst* getShapeInst() const;
};

AptCharacterShapeInst* AptCIH::getShapeInst() const {
    return m_inst;
}
