// 0x802F2308 (8 bytes)
class EGraphics {
public:
    int GetNormalMapMatrix();
};

int EGraphics::GetNormalMapMatrix() {
    return (int)((char*)this + 0x40);
}
