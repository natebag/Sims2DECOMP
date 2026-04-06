// PaneItem::SetPosY(float)
// Address: 0x803A07F8 | Size: 8 bytes
// Pattern: Stores float at offset 16

struct PaneItem {
    char pad[16];
    float m_posY;  // at offset 16
};

extern "C" void PaneItem_SetPosY(PaneItem* this_, float y) {
    this_->m_posY = y;
}
