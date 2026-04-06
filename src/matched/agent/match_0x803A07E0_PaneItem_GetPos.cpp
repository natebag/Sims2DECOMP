// PaneItem::GetPos(void)
// Address: 0x803A07E0 | Size: 8 bytes
// Pattern: Returns this + 12 (address of position field)

struct EVec2 {
    float x, y;
};

struct PaneItem {
    char pad[12];
    EVec2 m_pos;  // at offset 12
};

extern "C" EVec2* PaneItem_GetPos(PaneItem* this_) {
    return &this_->m_pos;
}
