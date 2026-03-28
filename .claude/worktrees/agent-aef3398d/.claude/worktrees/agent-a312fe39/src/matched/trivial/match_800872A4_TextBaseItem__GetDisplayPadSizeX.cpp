// 0x800872A4 (8 bytes)
class TextBaseItem {
public:
    float GetDisplayPadSizeX();
};

float TextBaseItem::GetDisplayPadSizeX() {
    return *(float*)((char*)this + 0x34);
}
