// 0x800878AC (8 bytes)
class IconItem {
public:
    float GetAlpha();
};

float IconItem::GetAlpha() {
    return *(float*)((char*)this + 0x2C);
}
