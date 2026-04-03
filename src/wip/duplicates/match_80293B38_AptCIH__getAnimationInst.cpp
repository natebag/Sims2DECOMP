// 0x80293B38 (8 bytes)
class AptCIH {
public:
    int getAnimationInst();
};

int AptCIH::getAnimationInst() {
    return *(int*)((char*)this + 0x4C);
}
