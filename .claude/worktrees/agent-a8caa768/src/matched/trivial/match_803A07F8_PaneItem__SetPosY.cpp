// 0x803A07F8 (8 bytes)
class PaneItem {
public:
    void SetPosY(float p);
};

void PaneItem::SetPosY(float p) {
    *(float*)((char*)this + 0x10) = p;
}
