// 0x800871D8 TextBaseItem::SetPos (20b)
// FLAGS: -fno-schedule-insns

struct EVec2 { int x, y; };

struct TextBaseItem {
    char _pad[36];
    int m_x;
    int m_y;
};

void TextBaseItem__SetPos(TextBaseItem *self, EVec2 *v) {
    int y = v->y;
    int x = v->x;
    self->m_y = y;
    self->m_x = x;
}
