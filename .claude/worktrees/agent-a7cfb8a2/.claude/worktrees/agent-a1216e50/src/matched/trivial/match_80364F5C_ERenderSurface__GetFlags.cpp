// 0x80364F5C (8 bytes)
class ERenderSurface {
public:
    int GetFlags();
};

int ERenderSurface::GetFlags() {
    return *(int*)((char*)this + 0x8);
}
