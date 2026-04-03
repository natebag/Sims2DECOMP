// 0x800871C0 (8 bytes)
class TextBaseItem {
public:
    float GetShadowAlpha();
};

float TextBaseItem::GetShadowAlpha() {
    return *(float*)((char*)this + 0x48);
}
