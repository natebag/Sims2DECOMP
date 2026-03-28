// 0x80364EB8 (8 bytes)
class ERenderSurface {
public:
    int GetXSize();
};

int ERenderSurface::GetXSize() {
    return *(int*)((char*)this + 0x0);
}
