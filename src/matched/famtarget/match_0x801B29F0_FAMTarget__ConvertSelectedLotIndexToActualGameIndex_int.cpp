// 0x801B29F0 FAMTarget::ConvertSelectedLotIndexToActualGameIndex(int) (8 B)
struct FAMTarget { int ConvertSelectedLotIndexToActualGameIndex(int); };
int FAMTarget::ConvertSelectedLotIndexToActualGameIndex(int idx) { return idx + 13; }
