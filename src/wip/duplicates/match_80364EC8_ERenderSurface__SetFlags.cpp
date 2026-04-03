// 0x80364EC8 (8 bytes)
class ERenderSurface {
public:
    void SetFlags(int p);
};

void ERenderSurface::SetFlags(int p) {
    *(int*)((char*)this + 0x8) = p;
}
