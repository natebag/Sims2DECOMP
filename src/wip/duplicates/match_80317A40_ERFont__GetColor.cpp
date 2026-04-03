// 0x80317A40 (8 bytes)
class ERFont {
public:
    int GetColor();
};

int ERFont::GetColor() {
    return (int)((char*)this + 0x58);
}
