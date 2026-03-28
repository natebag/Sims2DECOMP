// 0x802F22F0 (8 bytes)
class EGraphics {
public:
    int GetScreenYOffset();
};

int EGraphics::GetScreenYOffset() {
    return *(int*)((char*)this + 0x24);
}
