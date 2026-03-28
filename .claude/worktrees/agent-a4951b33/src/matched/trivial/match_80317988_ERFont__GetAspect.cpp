// 0x80317988 (8 bytes)
class ERFont {
public:
    float GetAspect();
};

float ERFont::GetAspect() {
    return *(float*)((char*)this + 0x50);
}
