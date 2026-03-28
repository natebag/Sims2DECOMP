struct ENgcMemoryCard {
    int CheckForOverwriteSpace(unsigned int, unsigned int, int, int *result);
};
int ENgcMemoryCard::CheckForOverwriteSpace(unsigned int, unsigned int, int, int *result) { *result = 0; return 1; }
