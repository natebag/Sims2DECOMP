// 0x8008739C (8 bytes)
class TextBaseItem {
public:
    float GetFontSize();
};

float TextBaseItem::GetFontSize() {
    return *(float*)((char*)this + 0x54);
}
