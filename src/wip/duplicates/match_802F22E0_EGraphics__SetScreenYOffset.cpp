// 0x802F22E0 (8 bytes)
class EGraphics {
public:
    void SetScreenYOffset(int p);
};

void EGraphics::SetScreenYOffset(int p) {
    *(int*)((char*)this + 0x24) = p;
}
