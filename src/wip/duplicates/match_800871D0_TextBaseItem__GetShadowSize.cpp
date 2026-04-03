// 0x800871D0 (8 bytes)
class TextBaseItem {
public:
    float GetShadowSize();
};

float TextBaseItem::GetShadowSize() {
    return *(float*)((char*)this + 0x4C);
}
