// 0x80087354 (8 bytes)
class TextBaseItem {
public:
    int GetFont();
};

int TextBaseItem::GetFont() {
    return *(int*)((char*)this + 0x50);
}
