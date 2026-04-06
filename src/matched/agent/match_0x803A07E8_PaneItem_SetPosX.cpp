// 0x803A07E8 PaneItem::SetPosX (8b)

struct PaneItem {
    char pad[12];
    float m_posX;  // at offset 12
};

void PaneItem_SetPosX(PaneItem* this_, float x) {
    this_->m_posX = x;
}

extern "C" void _ZN8PaneItem8SetPosXEf(PaneItem* this_, float x) {
    PaneItem_SetPosX(this_, x);
}
