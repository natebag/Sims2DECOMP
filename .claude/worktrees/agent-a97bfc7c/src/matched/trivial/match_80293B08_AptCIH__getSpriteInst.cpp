// 0x80293B08 (8 bytes)
class AptCIH {
public:
    int getSpriteInst();
};

int AptCIH::getSpriteInst() {
    return *(int*)((char*)this + 0x4C);
}
