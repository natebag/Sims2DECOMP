// 0x80087198 (8 bytes)
class TextBaseItem {
public:
    int GetColor();
};

int TextBaseItem::GetColor() {
    return *(int*)((char*)this + 0x44);
}
