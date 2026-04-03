// 0x80293B18 (8 bytes)
class AptCIH {
public:
    int getTextInst();
};

int AptCIH::getTextInst() {
    return *(int*)((char*)this + 0x4C);
}
