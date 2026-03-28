// 0x80293B30 (8 bytes)
class AptCIH {
public:
    int getButtonInst();
};

int AptCIH::getButtonInst() {
    return *(int*)((char*)this + 0x4C);
}
