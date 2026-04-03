// 0x80293B28 (8 bytes)
class AptCIH {
public:
    int getMorphInst();
};

int AptCIH::getMorphInst() {
    return *(int*)((char*)this + 0x4C);
}
