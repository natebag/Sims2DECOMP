// 0x8008725C (8 bytes)
class TextBaseItem {
public:
    float GetDisplaySizeY();
};

float TextBaseItem::GetDisplaySizeY() {
    return *(float*)((char*)this + 0x30);
}
