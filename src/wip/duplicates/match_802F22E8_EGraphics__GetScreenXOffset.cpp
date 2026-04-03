// 0x802F22E8 (8 bytes)
class EGraphics {
public:
    int GetScreenXOffset();
};

int EGraphics::GetScreenXOffset() {
    return *(int*)((char*)this + 0x20);
}
