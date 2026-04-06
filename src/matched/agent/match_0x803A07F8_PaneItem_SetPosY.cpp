// 0x803A07F8 PaneItem::SetPosY (8b)

struct PaneItem {
    char pad[16];
    float m_posY;  // at offset 16
};

void PaneItem_SetPosY(PaneItem* this_, float y) {
    this_->m_posY = y;
}

extern "C" void _ZN8PaneItem8SetPosYEf(PaneItem* this_, float y) {
    PaneItem_SetPosY(this_, y);
}
