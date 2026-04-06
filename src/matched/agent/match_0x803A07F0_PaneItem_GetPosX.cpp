// 0x803A07F0 PaneItem::GetPosX (8b)

struct PaneItem {
    char pad[12];
    float m_posX;  // at offset 12
};

float PaneItem_GetPosX(PaneItem* this_) {
    return this_->m_posX;
}

extern "C" float _ZNK8PaneItem8GetPosXEv(PaneItem* this_) {
    return PaneItem_GetPosX(this_);
}
