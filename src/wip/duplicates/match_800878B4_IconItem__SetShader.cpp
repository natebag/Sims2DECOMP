// 0x800878B4 (8 bytes)
class IconItem {
public:
    void SetShader(int p);
};

void IconItem::SetShader(int p) {
    *(int*)((char*)this + 0x30) = p;
}
