// PaneItem::SetPosX(float)
// Address: 0x803A07E8 | Size: 8 bytes
// Pattern: Stores float at offset 12

struct PaneItem {
    char pad[12];
    float m_posX;  // at offset 12
};

extern "C" void PaneItem_SetPosX(PaneItem* this_, float x) {
    this_->m_posX = x;
}
