// 0x802F2240 (8 bytes)
class EGraphics {
public:
    int GetScreenYSize();
};

int EGraphics::GetScreenYSize() {
    return *(int*)((char*)this + 0x1C);
}
