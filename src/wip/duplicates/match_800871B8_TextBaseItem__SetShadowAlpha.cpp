// 0x800871B8 (8 bytes)
class TextBaseItem {
public:
    void SetShadowAlpha(float p);
};

void TextBaseItem::SetShadowAlpha(float p) {
    *(float*)((char*)this + 0x48) = p;
}
