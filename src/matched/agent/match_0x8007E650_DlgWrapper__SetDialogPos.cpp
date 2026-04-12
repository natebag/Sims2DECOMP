// 0x8007E650 DlgWrapper::SetDialogPos (20b)
// FLAGS: -fno-schedule-insns

struct EVec2 { int x, y; };

struct DlgWrapper {
    char _pad[188];
    int m_x;
    int m_y;
};

void DlgWrapper__SetDialogPos(DlgWrapper *self, EVec2 *v) {
    int y = v->y;
    int x = v->x;
    self->m_y = y;
    self->m_x = x;
}
