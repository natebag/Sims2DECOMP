typedef int EMC_SaveType;
class ENgcMemoryCard { public: int CheckForOverwriteSpace(unsigned int, unsigned int, EMC_SaveType, int &); };
int ENgcMemoryCard::CheckForOverwriteSpace(unsigned int, unsigned int, EMC_SaveType, int &result) { result = 0; return 1; }
