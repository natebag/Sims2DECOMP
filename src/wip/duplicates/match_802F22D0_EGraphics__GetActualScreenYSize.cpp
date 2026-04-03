// 0x802F22D0 (8 bytes)
class EGraphics {
public:
    int GetActualScreenYSize();
};

int EGraphics::GetActualScreenYSize() {
    return *(int*)((char*)this + 0x1C);
}
