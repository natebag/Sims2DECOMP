// PaneItem::GetPosX(void) const
// Address: 0x803A07F0 | Size: 8 bytes
// Pattern: Loads float from offset 12, returns in f1

struct PaneItem {
    char pad[12];
    float m_posX;  // at offset 12
};

extern "C" float PaneItem_GetPosX(PaneItem* this_) {
    return this_->m_posX;
}
