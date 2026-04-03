// 0x8008720C (8 bytes)
class TextBaseItem {
public:
    float GetPosY();
};

float TextBaseItem::GetPosY() {
    return *(float*)((char*)this + 0x28);
}
