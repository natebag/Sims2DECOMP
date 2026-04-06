// PaneItem::GetPosY(void) const
// Address: 0x803A0800 | Size: 8 bytes
// Pattern: Loads float from offset 16, returns in f1

struct PaneItem {
    char pad[16];
    float m_posY;  // at offset 16
};

extern "C" float PaneItem_GetPosY(PaneItem* this_) {
    return this_->m_posY;
}
