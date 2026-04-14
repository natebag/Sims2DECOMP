// 0x801B29F0 (8 bytes)
// FAMTarget::ConvertSelectedLotIndexToActualGameIndex(int)
// addi r3, r4, 13; blr
class FAMTarget {
public:
    int ConvertSelectedLotIndexToActualGameIndex(int index);
};

int FAMTarget::ConvertSelectedLotIndexToActualGameIndex(int index) {
    return index + 13;
}
