// 0x803A07CC (20 bytes) - PaneItem::SetPos(EVec2 &)
// lwz r0, 4(r4); lwz r9, 0(r4); stw r0, 16(r3); stw r9, 12(r3); blr
struct EVec2 { int x, y; };
class PaneItem {
    char pad[12]; // 0x00-0x0B
    int m_posX; // 0x0C
    int m_posY; // 0x10
public:
    void SetPos(EVec2& v);
};
void PaneItem::SetPos(EVec2& v) {
    m_posY = v.y;
    m_posX = v.x;
}
