// 0x802847A4 (8 bytes)
class AptAnimationPoolData {
public:
    void setInputMask(int p);
};

void AptAnimationPoolData::setInputMask(int p) {
    *(int*)((char*)this + 0x94) = p;
}
