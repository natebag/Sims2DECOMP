// 0x802F2238 (8 bytes)
class EGraphics {
public:
    int GetScreenXSize();
};

int EGraphics::GetScreenXSize() {
    return *(int*)((char*)this + 0x18);
}
