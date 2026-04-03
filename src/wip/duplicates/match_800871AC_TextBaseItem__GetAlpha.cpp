// 0x800871AC (8 bytes)
class TextBaseItem {
public:
    float GetAlpha();
};

float TextBaseItem::GetAlpha() {
    return *(float*)((char*)(*(int*)((char*)this + 0x44)) + 0xC);
}
