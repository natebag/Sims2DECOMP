// 0x802F221C (8 bytes)
class EGraphics {
public:
    int GetCoordinateSystem();
};

int EGraphics::GetCoordinateSystem() {
    return *(int*)((char*)this + 0x98);
}
