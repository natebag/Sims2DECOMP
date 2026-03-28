typedef int EMC_SaveType;
class ENgcMemoryCard { public: int IsSpaceAvailable(unsigned int, EMC_SaveType, int &); };
int ENgcMemoryCard::IsSpaceAvailable(unsigned int, EMC_SaveType, int &result) { result = 0; return 1; }
