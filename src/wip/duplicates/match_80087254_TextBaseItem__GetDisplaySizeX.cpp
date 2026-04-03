// 0x80087254 (8 bytes)
class TextBaseItem {
public:
    float GetDisplaySizeX();
};

float TextBaseItem::GetDisplaySizeX() {
    return *(float*)((char*)this + 0x2C);
}
