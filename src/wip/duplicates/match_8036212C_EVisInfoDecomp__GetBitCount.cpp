// 0x8036212C (8 bytes)
class EVisInfoDecomp {
public:
    int GetBitCount();
};

int EVisInfoDecomp::GetBitCount() {
    return *(int*)((char*)this + 0x8);
}
