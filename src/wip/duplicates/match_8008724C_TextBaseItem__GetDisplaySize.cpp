// 0x8008724C (8 bytes)
class TextBaseItem {
public:
    int GetDisplaySize();
};

int TextBaseItem::GetDisplaySize() {
    return (int)((char*)this + 0x2C);
}
