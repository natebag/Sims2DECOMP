// 0x800871C8 (8 bytes)
class TextBaseItem {
public:
    void SetShadowSize(float p);
};

void TextBaseItem::SetShadowSize(float p) {
    *(float*)((char*)this + 0x4C) = p;
}
