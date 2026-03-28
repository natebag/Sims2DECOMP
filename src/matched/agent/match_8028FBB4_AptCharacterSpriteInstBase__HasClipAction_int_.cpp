struct AptCharacterSpriteInstBase {
    char pad[0x1C];
    int m_clipActions;

    int HasClipAction(int action);
};

int AptCharacterSpriteInstBase::HasClipAction(int action) {
    return (m_clipActions >> 8) & action;
}
