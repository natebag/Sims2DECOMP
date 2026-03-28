// 0x80293B40 (8 bytes)
class AptCIH {
public:
    int getShapeInst();
};

int AptCIH::getShapeInst() {
    return *(int*)((char*)this + 0x4C);
}
