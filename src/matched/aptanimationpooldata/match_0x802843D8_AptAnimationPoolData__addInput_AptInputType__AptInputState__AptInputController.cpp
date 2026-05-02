// 0x802843D8 AptAnimationPoolData::addInput(AptInputType, AptInputState, AptInputController) (56b)
enum AptInputType {};
enum AptInputState {};
enum AptInputController {};

struct AptAnimationPoolData {
    void addInput(unsigned int packed);
    void addInput(AptInputType type, AptInputState state, AptInputController controller);
};

void AptAnimationPoolData::addInput(AptInputType type, AptInputState state, AptInputController controller) {
    unsigned int stateBits = ((unsigned int)state << 10) & 0x1fc00;
    unsigned int packed = (unsigned int)type << 17;
    stateBits |= 1;
    unsigned int controllerBits = ((unsigned int)controller << 2) & 0x3fc;
    packed |= stateBits;
    packed |= controllerBits;
    addInput(packed);
}
