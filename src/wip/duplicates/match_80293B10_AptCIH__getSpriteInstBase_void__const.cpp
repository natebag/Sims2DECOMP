struct AptCharacterSpriteInstBase;

struct AptCIH {
    char pad[0x4C];
    AptCharacterSpriteInstBase* m_inst;

    AptCharacterSpriteInstBase* getSpriteInstBase() const;
};

AptCharacterSpriteInstBase* AptCIH::getSpriteInstBase() const {
    return m_inst;
}
