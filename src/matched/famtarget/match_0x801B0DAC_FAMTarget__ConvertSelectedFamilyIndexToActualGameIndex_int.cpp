// 0x801B0DAC FAMTarget::ConvertSelectedFamilyIndexToActualGameIndex(int) (8 B)
struct FAMTarget { int ConvertSelectedFamilyIndexToActualGameIndex(int); };
int FAMTarget::ConvertSelectedFamilyIndexToActualGameIndex(int idx) { return idx + 20; }
