struct AptCharacterAnimationInst;

struct AptCIH {
    char pad[0x4C];
    AptCharacterAnimationInst* m_inst;

    AptCharacterAnimationInst* getAnimationInst() const;
};

AptCharacterAnimationInst* AptCIH::getAnimationInst() const {
    return m_inst;
}
