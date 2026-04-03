// 0x802F22D8 (8 bytes)
class EGraphics {
public:
    void SetScreenXOffset(int p);
};

void EGraphics::SetScreenXOffset(int p) {
    *(int*)((char*)this + 0x20) = p;
}
