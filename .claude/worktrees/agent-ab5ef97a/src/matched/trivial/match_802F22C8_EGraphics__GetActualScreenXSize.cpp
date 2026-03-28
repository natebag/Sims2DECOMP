// 0x802F22C8 (8 bytes)
class EGraphics {
public:
    int GetActualScreenXSize();
};

int EGraphics::GetActualScreenXSize() {
    return *(int*)((char*)this + 0x18);
}
