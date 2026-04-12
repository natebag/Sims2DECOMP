// 0x8006CA68 ScrollingTextBox::SetScrollVelocity (20b)
// FLAGS: -fno-schedule-insns

struct EVec2 { int x, y; };

struct ScrollingTextBox {
    char _pad[20];
    int m_x;
    int m_y;
};

void ScrollingTextBox__SetScrollVelocity(ScrollingTextBox *self, EVec2 *v) {
    int y = v->y;
    int x = v->x;
    self->m_y = y;
    self->m_x = x;
}
