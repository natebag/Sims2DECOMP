// 0x803A07E0 (8 bytes)
class PaneItem {
public:
    int GetPos();
};

int PaneItem::GetPos() {
    return (int)((char*)this + 0xC);
}
