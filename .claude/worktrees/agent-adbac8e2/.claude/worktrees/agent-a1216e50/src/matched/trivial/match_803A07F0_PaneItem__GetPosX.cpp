// 0x803A07F0 (8 bytes)
class PaneItem {
public:
    float GetPosX();
};

float PaneItem::GetPosX() {
    return *(float*)((char*)this + 0xC);
}
