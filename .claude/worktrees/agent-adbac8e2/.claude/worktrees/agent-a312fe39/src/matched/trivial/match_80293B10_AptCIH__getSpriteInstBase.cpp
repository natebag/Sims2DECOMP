// 0x80293B10 (8 bytes)
class AptCIH {
public:
    int getSpriteInstBase();
};

int AptCIH::getSpriteInstBase() {
    return *(int*)((char*)this + 0x4C);
}
