// 0x800872AC (8 bytes)
class TextBaseItem {
public:
    float GetDisplayPadSizeY();
};

float TextBaseItem::GetDisplayPadSizeY() {
    return *(float*)((char*)this + 0x38);
}
