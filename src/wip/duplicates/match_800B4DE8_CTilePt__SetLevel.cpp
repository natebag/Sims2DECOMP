// 0x800B4DE8 (8 bytes)
class CTilePt {
public:
    void SetLevel(int p);
};

void CTilePt::SetLevel(int p) {
    *(unsigned char*)((char*)this + 0x2) = (unsigned char)p;
}
