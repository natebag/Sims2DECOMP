// 0x800871EC (8 bytes)
class TextBaseItem {
public:
    int GetPos();
};

int TextBaseItem::GetPos() {
    return (int)((char*)this + 0x24);
}
