// 0x803A07E0 PaneItem::GetPos (8b)

struct EVec2 {
    float x, y;
};

struct PaneItem {
    char pad[12];
    EVec2 m_pos;  // at offset 12
};

EVec2* PaneItem_GetPos(PaneItem* this_) {
    return (EVec2*)((char*)this_ + 12);
}

extern "C" EVec2* _ZN8PaneItem6GetPosEv(PaneItem* this_) {
    return PaneItem_GetPos(this_);
}
