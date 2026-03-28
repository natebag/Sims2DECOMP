// 0x801B0DAC (8 bytes)
// FAMTarget::ConvertSelectedFamilyIndexToActualGameIndex(int)
// addi r3, r4, 20; blr
class FAMTarget {
public:
    int ConvertSelectedFamilyIndexToActualGameIndex(int index);
};

int FAMTarget::ConvertSelectedFamilyIndexToActualGameIndex(int index) {
    return index + 20;
}
