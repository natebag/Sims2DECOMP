struct AptCharacterSpriteInst;

struct AptCIH {
    char pad[0x4C];
    AptCharacterSpriteInst* m_spriteInst;

    AptCharacterSpriteInst* getSpriteInst() const;
};

AptCharacterSpriteInst* AptCIH::getSpriteInst() const {
    return m_spriteInst;
}
