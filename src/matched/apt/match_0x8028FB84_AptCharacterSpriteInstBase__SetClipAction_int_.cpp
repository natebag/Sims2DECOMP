// 0x8028FB84 (24B) AptCharacterSpriteInstBase::SetClipAction(int)

struct AptCSIB_ClipFlags {
    signed int flags : 24;
    unsigned int low : 8;
};

struct AptCharacterSpriteInstBase_Set {
    char pad[0x1C];
    AptCSIB_ClipFlags m_clipActions;

    void SetClipAction(int action);
};

void AptCharacterSpriteInstBase_Set::SetClipAction(int action) {
    m_clipActions.flags |= action;
}
