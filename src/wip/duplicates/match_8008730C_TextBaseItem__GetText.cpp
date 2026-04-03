// 0x8008730C (8 bytes)
class TextBaseItem {
public:
    int GetText();
};

int TextBaseItem::GetText() {
    return *(int*)((char*)this + 0x20);
}
