// 0x8028FB9C (24B) AptCharacterSpriteInstBase::RemoveClipAction(int)

struct AptCSIB_ClipFlags_R {
    signed int flags : 24;
    unsigned int low : 8;
};

struct AptCharacterSpriteInstBase_Remove {
    char pad[0x1C];
    AptCSIB_ClipFlags_R m_clipActions;

    void RemoveClipAction(int action);
};

void AptCharacterSpriteInstBase_Remove::RemoveClipAction(int action) {
    m_clipActions.flags &= ~action;
}
