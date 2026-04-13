// 0x801430BC SpriteSlot::AlternateWithSprite(int, int) (24B)
struct SpriteSlot {
    char pad[0x1C];
    int m_spriteId;
    int m_flags2;
    char pad2[0x24];
    int m_flags;
};
void SpriteSlot_AlternateWithSprite(SpriteSlot* self, int spriteId, int param) {
    int flags = self->m_flags;
    self->m_spriteId = spriteId;
    flags |= 0x40;
    self->m_flags2 = param;
    self->m_flags = flags;
}
