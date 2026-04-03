// 0x802F2224 (8 bytes)
class EGraphics {
public:
    void SetCoordinateSystem(int p);
};

void EGraphics::SetCoordinateSystem(int p) {
    *(int*)((char*)this + 0x98) = p;
}
