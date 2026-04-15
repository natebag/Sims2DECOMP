// 0x800872E0 TextBaseItem::SetYPosCentered(bool) (44B)

struct TextBlock {
    char pad[0x38];
    int m_flags;
};

struct TextBaseItem {
    char pad[0x20];
    TextBlock m_textBlock;
};

void TextBaseItem_SetYPosCentered(TextBaseItem* self, int center) {
    TextBlock* tb = &self->m_textBlock;
    if (center) {
        tb->m_flags |= 0x20;
        return;
    }
    tb->m_flags &= ~0x20;
}
