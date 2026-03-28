// 0x803A0800 (8 bytes)
class PaneItem {
public:
    float GetPosY();
};

float PaneItem::GetPosY() {
    return *(float*)((char*)this + 0x10);
}
