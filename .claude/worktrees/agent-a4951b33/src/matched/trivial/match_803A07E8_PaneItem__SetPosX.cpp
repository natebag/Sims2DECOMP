// 0x803A07E8 (8 bytes)
class PaneItem {
public:
    void SetPosX(float p);
};

void PaneItem::SetPosX(float p) {
    *(float*)((char*)this + 0xC) = p;
}
