struct EMC_Operation;
struct ENgcMemoryCard {
    int GetFileListA(unsigned int, char *, unsigned int, void *, EMC_Operation *);
};
int ENgcMemoryCard::GetFileListA(unsigned int, char *, unsigned int, void *, EMC_Operation *) { return 1; }
