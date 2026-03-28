// 0x800871FC (8 bytes)
class TextBaseItem {
public:
    float GetPosX();
};

float TextBaseItem::GetPosX() {
    return *(float*)((char*)this + 0x24);
}
