// 0x80293B48 (8 bytes)
class AptCIH {
public:
    int getCharacterInst();
};

int AptCIH::getCharacterInst() {
    return *(int*)((char*)this + 0x4C);
}
