// 0x80087204 (8 bytes)
class TextBaseItem {
public:
    void SetPosY(float p);
};

void TextBaseItem::SetPosY(float p) {
    *(float*)((char*)this + 0x28) = p;
}
