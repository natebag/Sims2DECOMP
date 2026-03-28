// 0x80364EC0 (8 bytes)
class ERenderSurface {
public:
    int GetYSize();
};

int ERenderSurface::GetYSize() {
    return *(int*)((char*)this + 0x4);
}
