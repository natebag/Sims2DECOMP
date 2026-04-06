// 0x803A0800 PaneItem::GetPosY (8b)

struct PaneItem {
    char pad[16];
    float m_posY;  // at offset 16
};

float PaneItem_GetPosY(PaneItem* this_) {
    return this_->m_posY;
}

extern "C" float _ZNK8PaneItem8GetPosYEv(PaneItem* this_) {
    return PaneItem_GetPosY(this_);
}
