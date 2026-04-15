// 0x800872B4 TextBaseItem::SetVerticalCenter(bool) (44B)

struct TextBlock {
    char pad[0x38];
    int m_flags;
};

struct TextBaseItem {
    char pad[0x20];
    TextBlock m_textBlock;
};

void TextBaseItem_SetVerticalCenter(TextBaseItem* self, int center) {
    TextBlock* tb = &self->m_textBlock;
    if (center) {
        tb->m_flags |= 8;
        return;
    }
    tb->m_flags &= ~8;
}
