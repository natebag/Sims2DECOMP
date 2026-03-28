struct AptCharacterInst;

struct AptFile {
    char pad[0x10];
    AptCharacterInst* m_mainCharacter;

    AptCharacterInst* GetMainCharacter() const;
};

AptCharacterInst* AptFile::GetMainCharacter() const {
    return m_mainCharacter;
}
