// 0x80293B20 (8 bytes)
class AptCIH {
public:
    int getStaticTextInst();
};

int AptCIH::getStaticTextInst() {
    return *(int*)((char*)this + 0x4C);
}
