// 0x800878A4 (8 bytes)
class IconItem {
public:
    void SetAlpha(float p);
};

void IconItem::SetAlpha(float p) {
    *(float*)((char*)this + 0x2C) = p;
}
