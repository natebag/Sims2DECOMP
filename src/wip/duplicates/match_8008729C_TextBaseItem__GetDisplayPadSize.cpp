// 0x8008729C (8 bytes)
class TextBaseItem {
public:
    int GetDisplayPadSize();
};

int TextBaseItem::GetDisplayPadSize() {
    return (int)((char*)this + 0x34);
}
