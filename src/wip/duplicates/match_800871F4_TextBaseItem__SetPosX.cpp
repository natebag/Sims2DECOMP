// 0x800871F4 (8 bytes)
class TextBaseItem {
public:
    void SetPosX(float p);
};

void TextBaseItem::SetPosX(float p) {
    *(float*)((char*)this + 0x24) = p;
}
