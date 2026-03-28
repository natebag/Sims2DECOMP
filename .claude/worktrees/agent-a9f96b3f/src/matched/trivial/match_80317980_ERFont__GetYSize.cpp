// 0x80317980 (8 bytes)
class ERFont {
public:
    float GetYSize();
};

float ERFont::GetYSize() {
    return *(float*)((char*)this + 0x4C);
}
