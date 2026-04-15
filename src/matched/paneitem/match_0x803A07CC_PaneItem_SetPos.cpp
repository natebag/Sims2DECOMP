// FLAGS: -fno-schedule-insns
// 0x803A07CC PaneItem::SetPos(EVec2&) (20B)

struct EVec2 { int x, y; };

struct PaneItem {
    char pad[12];
    int m_posX;  // +12
    int m_posY;  // +16
    void SetPos(EVec2& v);
};

void PaneItem::SetPos(EVec2& v) {
    int y = v.y;
    int x = v.x;
    m_posY = y;
    m_posX = x;
}
