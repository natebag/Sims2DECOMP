// 0x800873A4 (8 bytes)
class TextBaseItem {
public:
    int GetStyle();
};

int TextBaseItem::GetStyle() {
    return *(int*)((char*)this + 0x6C);
}
